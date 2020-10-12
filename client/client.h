#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8080
#define SEND "SEND"
#define RECEIVE "RECV"
#define SIGN  "SIGN"
#define REGI  "REGI"
#define QUIT "QUIT"
#define DATA "DATA"
#define IP   "192.168.56.130"

struct st_mail{
    char operation[5];//选择
    char addr[64];//邮箱地址
    char pwd[64];//邮箱密码
    char title[64];//标题
    char content[512];//内容
    char toaddr[315];//收件人地址
};
struct filehelp{

    char operation[5];
    char file_name[251];
    char file[768]; //文件
};
extern struct st_mail c_user;



struct st_mail_list{

    int sum;
    struct st_mail mails[20];
};


#endif // CLIENT_H
