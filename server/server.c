/*socket tcp服务器端*/
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <mysql.h>
#include "db.h"

int main()
{
	
	int serversocket;//调用socket函数返回的文件描述符
	int clientsocket;
	
	struct sockaddr_in server_addr;//声明两个套接字sockaddr_in结构体变量，分别表示客户端和服务器
	struct sockaddr_in client_addr;
	struct st_mail mail;

	MYSQL *conn_ptr;

	/*socket函数，失败返回-1
	  第一个参数表示使用的地址类型，一般都是ipv4，AF_INET
	  第二个参数表示套接字类型：tcp：面向连接的稳定数据传输SOCK_STREAM
	  第三个参数设置为0 */	
	if ((serversocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		return 1;
	}
	
	memset(&server_addr, 0,sizeof(server_addr));//初始化服务器端的套接字，并用htons和htonl将端口和地址转成网络字节序
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);	
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//ip可是本服务器的ip，也可以用宏INADDR_ANY代替，代表0.0.0.0，表明所有地址
	
	//连接服务器套接字
	if (bind(serversocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("connect");
		return 1;
	}
	
	//设置服务器上的socket为监听状态
	if (listen(serversocket, 5) < 0) {
		perror("listen");
		return 1;
	}
	
	while (1) {
		printf("Listening on port: %d\n", SERVER_PORT);
		/*调用accept函数后，会进入阻塞状态
		//accept返回一个套接字的文件描述符，这样服务器端便有两个套接字的文件描述符，serversocket和clientsocket。
		//serversocket仍然继续在监听状态，clientsocket则负责接收和发送数据
		//出错返回-1
		//用于接收发送信息的套接字的内存长度*/
		int client_addr_len = sizeof(client_addr);
		clientsocket = accept(serversocket, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
		if (clientsocket < 0) {
			perror("accept");
			continue;
		}
		//收到请求之后开启一个子进程
		if (!fork()) {
			//printf("Recv client data...\n");
			
			//inet_ntoa ip地址转换函数，将网络字节序IP转换为点分十进制IP
			//输出客户端ip以及端口
			printf("Client IP is %s\n", inet_ntoa(client_addr.sin_addr));
			printf("Client Port is %d\n", htons(client_addr.sin_port));
			
			while (1) {
				
				char buffer[1024];//定义一个用于缓存的数组				
				int recv_buffer_len;//接收到的数据的长度
				memset(buffer, 0, 1024);
				
				recv_buffer_len = recv(clientsocket, buffer, 1024, 0);
				
				if (recv_buffer_len < 0) {
					perror("recv");
					continue;
				}
				printf("recv operation is %s\n", buffer);
				

				
				if (strncmp(buffer, QUIT, 4) == 0) {
				
					//客户端接收完成所需信息后向服务器发送断开连接请求，服务器断开链接，结束循环
					close(clientsocket);
					break;
				
				}else if(strncmp(buffer,DATA,4)==0){
					printf("Client send file.\n");
					//响应文件请求
					struct filehelp cfile;
					memset(&cfile, 0, 1024);
					memcpy(&cfile, buffer, 1024);
					FILE *dest_fp;
					
					int src_len = strlen(cfile.file);
					
					if ((dest_fp = fopen(cfile.file_name, "wb+")) == NULL)
					{	
						printf("fopen %s failed./n", cfile.file_name);
						return -1;
					}
					
					fwrite(cfile.file, src_len, 1, dest_fp);
					fclose(dest_fp);					
												
				}else if (strncmp(buffer, REGI, 4) == 0) {
					//响应注册请求
					printf("Client register.\n");
					memset(&mail, 0, 1024);
					memcpy(&mail, buffer, 1024);
					printf("%s\n", mail.operation);
					printf("%s\n", mail.addr);
					printf("%s\n", mail.pwd);
					//查询该用户是否存在，若不存在则写入数据库，存在则向客户端返回注册失败信息
					db_select(clientsocket, mail);
				
				} else if (strncmp(buffer, SIGN, 4) == 0) {
					//响应登录请求
					printf("Client Sign in.....\n");
					memset(&mail, 0, 1024);
					memcpy(&mail, buffer, 1024);
					printf("%s\n", mail.operation);
					printf("%s\n", mail.addr);
					printf("%s\n", mail.pwd);
					//查询该用户是否存在及密码是否正确并对客户端返回相关信息
					db_sign(clientsocket, mail);
				
				} else if (strncmp(buffer, SEND, 4) == 0) {
					//响应发送
					printf("Client send new mail.....\n");
					memset(&mail, 0, 1024);
					memcpy(&mail, buffer, 1024);
					printf("%s\n", mail.toaddr);
					printf("%s\n", mail.title);
					printf("%s\n", mail.content);
					//将邮件内容写入数据库
					db_insert(clientsocket, mail);
				
				} else if (strncmp(buffer, RECEIVE, 4) == 0) {
					//响应查看收件箱请求
					printf("Client check mail_box.....\n");
					memset(&mail, 0, 1024);
					memcpy(&mail, buffer, 1024);
					printf("%s\n", mail.operation);
					printf("%s\n", mail.addr);
					//查找数据库中该用户的所有未读邮件并发送收件箱里所有未读邮件
					db_recv(clientsocket, mail);
					//更新未读邮件状态为已读
					db_update(mail);
				
				} else {					
					/*char msg{10};
					msg[10]="wrong operation\n";
					send(clientsocket, msg, strlen(msg), 0);*/			
				}
			}
		}
	}
	return 0;
}
