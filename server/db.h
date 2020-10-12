#ifndef DB_H
#define DB_H
#define SERVER_PORT 8080    	//默认服务器端口为8080
#define SEND "SEND"				//客户端发送请求	
#define RECEIVE "RECV"			//客户端收件请求
#define SIGN  "SIGN"			//客户端登录请求
#define REGI  "REGI"			//客户端注册请求
#define QUIT "QUIT"				//客户端断开连接
#define DATA "DATA"

struct st_mail {				//邮件结构体
	char operation[5];			//选择
	char addr[64];      		//发件人地址
	char pwd[64];       		//邮箱密码
	char title[64]; 			//标题
	char content[512];			//内容
	char toaddr[315];			//收件人地址

};

struct filehelp{
	
	char operation[5];
	char file_name[251];
	char file[768]; //文件
};


struct st_mail_list {			//邮件包结构体
	int sum;					//邮件数量
	struct st_mail mails[20];	//邮件数组
};

int db_sign(int _client, struct st_mail mail); //响应客户端登录函数
int db_insert(int _client,struct st_mail mail); //服务器数据库插入函数
int db_select(int _client,struct st_mail mail);//服务器数据库查找函数
int db_recv(int _client, struct st_mail mail); //响应客户端收件函数
int db_update(struct st_mail mail);		       //数据库更新状态函数


#endif