#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <mysql.h>
#include "db.h"
/************************************************************************************************************************
* Function Name :  db_insert()																							*
*																														*
* Description   :  服务器端将邮件信息写入数据库																			*
*																														*
* Date          :  2020－9－10																							*
*																														*
* Parameter     :  struct st_mail mail:邮件结构体，int _client为socket套接字											*
* Return Code   :  EXIT_SUCCESS 发送成功																				*
                   EXIT_FAIL    发送邮件失败																			*
																														*
* Author        :  张国安																								*
************************************************************************************************************************/

int db_insert(int _client, struct st_mail mail)
{
	MYSQL *conn_ptr;
	int res;
	char sql[512];
	unsigned long row=0;

	conn_ptr = mysql_init(NULL);

	if (!conn_ptr) {
		
		printf("mysql_init failed\n");
		return EXIT_FAILURE;
	}
	//root 为用户名 1234为密码 mail_db 为要连接的database

	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "1234", "mail_db", 3306, NULL, 0);

	if (conn_ptr) {
		memset(sql,0,512);

		if(strncmp(mail.operation, "SEND", 4) == 0) { //发送状态

			sprintf(sql, "insert into data ( recv_addr,mail_addr,content,title,status) values( '%s','%s','%s','%s','n');",mail.toaddr,mail.addr,mail.content,mail.title);
			res = mysql_query(conn_ptr,sql);
						
		
		} else if(strncmp(mail.operation, REGI, 4) == 0) { //注册

			sprintf(sql, "insert into users ( pwd,mail_addr) values('%s','%s');",mail.pwd,mail.addr);
			res = mysql_query(conn_ptr,sql);
		}

		if (!res) {

			row = (unsigned long)mysql_affected_rows(conn_ptr);//输出受影响的行数
			printf("Inserted %lu rows\n", row);

			if(row>0)
				send(_client, "1", 1,0);//发送成功
			else
				send(_client, "0", 1,0);//发送失败
		} else {

			fprintf(stderr, "Insert error %d: %sn", mysql_errno(conn_ptr), mysql_error(conn_ptr));//打印出错误代码及详细信息
		}
	} else {
		printf("Connection failed\n");
	}
	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}
/************************************************************************************************************************
* Function Name :  db_select()																								*
*																														*
* Description   :  客户端注册时，服务器端查询用户信息是否存在															*
*																														*
* Date          :  2020－9－10																							*
*																														*
* Parameter     :  struct st_mail mail:邮件结构体，int _client为socket套接字											*
* Return Code   :  EXIT_SUCCESS 查询成功																				*
                   EXIT_FAIL    查询失败																				*
																														*
* Author        :  张国安																								*
************************************************************************************************************************/


int db_select(int _client, struct st_mail mail)
{
	MYSQL *conn_ptr;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	MYSQL_FIELD *fd;
	int res, i, j;
	char sql[512];
	unsigned long row = 0;
	unsigned long a = 0;
	//printf("%s",mail.operation);
	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		return EXIT_FAILURE;
	}
	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "1234", "mail_db", 3306, NULL, 0);
	
	if (conn_ptr) {
		printf("Db connect OK\nmail.addr:%s\n",mail.addr);
		memset(sql,0,sizeof(sql));
		sprintf(sql, "select mail_addr from users where mail_addr='%s';",mail.addr); //查询语句

		res = mysql_query(conn_ptr,sql);

		if (!res) {

			res_ptr = mysql_store_result(conn_ptr); //取出结果集

			row = (unsigned long)mysql_affected_rows(conn_ptr);
			printf("%lu Rows\n", (unsigned long)mysql_num_rows(res_ptr));
			printf("%lu Rows\n",row);



			if (res_ptr) {  //成功取出
				printf("mail.operation:%s\n",mail.operation);
				if(strncmp(mail.operation,"REGI",4)==0) { //如果是注册请求，判断数据库存在用户
					sqlrow = mysql_fetch_row(res_ptr);
					printf("flag\n");
					if(row==0) {
						db_insert(_client,mail);
						printf("注册成功\n");
						send(_client, "1", strlen("1"),0);

					} else {

						printf("注册失败,请直接登录\n");
						send(_client, "0", strlen("0"),0);

					}
				}

				if(strncmp(mail.operation,"SIGN",4)==0) {

					sqlrow = mysql_fetch_row(res_ptr);
					strcmp(sqlrow[0],mail.pwd);

				}
			} else {
				fprintf(stderr, "Insert error %d: %sn",mysql_errno(conn_ptr),mysql_error(conn_ptr));

			}
			mysql_free_result(res_ptr);
		}
	} else {
		printf("Connection failed\n");
	}
	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}
/************************************************************************************************************************
* Function Name :  db_sign()																									*
*																														*
* Description   :  服务器响应客户端登录函数，服务器端查询用户账号密码是否正确并返回结果									*
*																														*
* Date          :  2020－9－10																							*
*																														*
* Parameter     :  struct st_mail mail:邮件结构体，int _client为socket套接字											*
* Return Code   :  EXIT_SUCCESS 查询成功																				*
                   EXIT_FAIL    查询失败																				*
																														*
* Author        :  张国安																								*
************************************************************************************************************************/


int db_sign(int _client, struct st_mail mail)
{
	MYSQL *conn_ptr;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	MYSQL_FIELD *fd;
	int res, i, j;
	char sql[512];
	unsigned long row = 0;
	unsigned long a = 0;
	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		return EXIT_FAILURE;
	}
	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "1234", "mail_db", 3306, NULL, 0);//root 为用户名 1234为密码 mail_db 为要连接的database

	if (conn_ptr) {
		printf("Signing in......mailaddr:%s\n",mail.addr);
		memset(sql,0,sizeof(sql));
		sprintf(sql, "select * from users where mail_addr='%s' AND pwd='%s';",mail.addr,mail.pwd); //查询语句

		res = mysql_query(conn_ptr,sql);

		if (res) {

			fprintf(stderr, "Insert error %d: %sn",mysql_errno(conn_ptr),mysql_error(conn_ptr));

		} else {
			res_ptr = mysql_store_result(conn_ptr); //取出结果集

			row = (unsigned long)mysql_affected_rows(conn_ptr);
			printf("insert %lu Rows\n", (unsigned long)mysql_num_rows(res_ptr));
			//printf("%lu Rows\n",row);

			if (res_ptr&&row>0) {  //成功取出

				printf("登录成功\n");
				send(_client, "1", strlen("1"),0);

			} else {

				printf("登录失败\n");
				send(_client, "0", strlen("0"),0);
			}

			mysql_free_result(res_ptr);
		}

	} else {

		printf("Connection failed\n");

	}

	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}
/************************************************************************************************************************
* Function Name :  db_recv()																								*
*																														*
* Description   :  服务器响应客户端收件请求的函数，服务器端查询用户收到的信件，然后打包所有未读信件发送给用户			*
*																														*
* Date          :  2020－9－10																							*
*																														*
* Parameter     :  struct st_mail mail:邮件结构体，int _client为socket套接字											*
* Return Code   :  EXIT_SUCCESS 查询成功																				*
                   EXIT_FAIL    查询失败																				*
																														*
* Author        :  张国安																								*
************************************************************************************************************************/

int db_recv(int _client, struct st_mail mail)
{
	MYSQL *conn_ptr;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	MYSQL_FIELD *fd;
	int res, i, j;
	char sql[512];
	struct st_mail_list list;
	memset(&list, 0, sizeof(struct st_mail_list));

	unsigned long row = 0;
	unsigned long a = 0;
	//printf("%s",mail.operation);
	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		return EXIT_FAILURE;
	}
	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "1234", "mail_db", 3306, NULL, 0);//root 为用户名 1234为密码 mail_db 为要连接的database

	if (conn_ptr) {
		printf("Db connect OK\nmail.addr:%s\n",mail.addr);
		memset(sql,0,sizeof(sql));
		sprintf(sql, "select * from data where recv_addr='%s' AND status='n';",mail.addr); //查询语句

		res = mysql_query(conn_ptr,sql);

		if (res) {
			fprintf(stderr, "Insert error %d: %sn",mysql_errno(conn_ptr),mysql_error(conn_ptr));


		} else {

			res_ptr = mysql_store_result(conn_ptr); //取出结果集
			row = (int)mysql_num_rows(res_ptr);
			list.sum = row;
			printf("%d 封未读邮件\n", list.sum);


			if (res_ptr&&row>0) {   //成功取出

				printf("%lu Rows\n", (unsigned long)mysql_num_rows(res_ptr));

				int j=0;
				while ((sqlrow = mysql_fetch_row(res_ptr))) { //依次取出记录

					strncpy(list.mails[j].title,sqlrow[1],strlen(sqlrow[1]));
					strncpy(list.mails[j].content, sqlrow[2],strlen(sqlrow[2]));
					strncpy(list.mails[j].addr,sqlrow[4],strlen(sqlrow[4]));
					j++;

				}

				send(_client, &list,sizeof(struct st_mail_list), 0);

			} else {

				printf("没有未读邮件\n");
				list.sum = 0;
				send(_client, &list,sizeof(struct st_mail_list), 0);
			}


			mysql_free_result(res_ptr);
		}

	} else {

		printf("Connection failed\n");

	}

	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}
/************************************************************************************************************************
* Function Name :  db_update()																							*
*																														*
* Description   :  服务器更新数据库，把用户读过的邮件的状态更新为已读													*
*																														*
* Date          :  2020－9－10																							*
*																														*
* Parameter     :  struct st_mail mail:邮件结构体，int _client为socket套接字											*
* Return Code   :  EXIT_SUCCESS 更新成功																				*
                   EXIT_FAIL    更新失败																				*
																														*
* Author        :  张国安																								*
************************************************************************************************************************/

int db_update(struct st_mail mail)
{
	MYSQL *conn_ptr;
	int res;
	char sql[512];
	memset(sql,'\0',512);

	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		printf("mysql_init failed\n");
		return EXIT_FAILURE;
	}
	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "1234","mail_db", 3306, NULL, 0);
	if (conn_ptr) {

		sprintf(sql,"update data set status='r' where recv_addr='%s';",mail.addr);

		res = mysql_query(conn_ptr,sql);

		if (!res) {
			printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(conn_ptr));//输出受影响的行数
		} else {
			fprintf(stderr, "Insert error %d: %sn",mysql_errno(conn_ptr),mysql_error(conn_ptr));//打印出错误代码及详细信息
		}
	} else {
		printf("Connection failed\n");
	}
	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}