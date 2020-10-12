#include "setup.h"
#include "ui_setup.h"
#include"client.h"
#include<QDebug>
#include<QPainter>
#include <QtNetwork>
#include <QMessageBox>

setup::setup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setup)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);//固定登录界面窗体大小
    this->setWindowIcon(QIcon(":/psources/sketch.jpg"));//设置窗体小图标
    this->setWindowTitle("FlowerMail注册");//设置窗体标题
    //注册按钮被点击触发槽函数
    connect(ui->registerImmeButton, SIGNAL(clicked(bool)),this,SLOT(registerImmeButtonPressed()));
}

//重写绘事件设置背景图片
void setup::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/psources/silk.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
//检查用户注册邮箱、密码是否合格
int setup::checkRegister(QString email, QString pwd,QString pwd2)
{
    if(email.length()>20)
    {
        return 1;
    }
    else if(pwd.length()>16||pwd.length()<6)
        return 2;
    else if(pwd.compare(pwd2)!=0)//两次密码输入不一致
        return 3;
    else
        return 0;
}

//注册操作
void setup::registerImmeButtonPressed()
{

    //服务器通信
    QTcpSocket *client; //socket句柄
    struct st_mail userRegi;
    memset(&userRegi,0,sizeof (userRegi));

    //读取用户输入的邮箱、密码、确认密码
    QString userEmail = ui->LineEmail->text();
    QString userPassword = ui->LinePassword->text();
    QString userPassword2=ui->linePassword2->text();

    //转换Qstring为普通字符串
    strcpy(userRegi.addr,userEmail.toUtf8().data());
    strcpy(userRegi.pwd,userPassword.toUtf8().data());
    strcpy(userRegi.operation,REGI);
    char pwd2[64];
    strcpy(pwd2,userPassword2.toUtf8().data());
    //strcmp(userRegi.pwd,pwd2)==0&&strlen(userRegi.addr)<=20&&strlen(userRegi.pwd)<=16&&
    if(checkRegister(userEmail,userPassword,userPassword2)==0)//确认注册信息没有任何问题
    {
        //连接服务器
        client = new QTcpSocket(this);
        client->connectToHost(QHostAddress(IP), 8080);
        client->write((char *)&userRegi,1024);

        // 获取服务器处理结果
        connect(client, &QTcpSocket::readyRead, [=]()
        {
            // 获取对方发送的内容
            QByteArray array = client->readAll();
            QString str = array;
            char str1[10];
            strcpy(str1,str.toUtf8().data());
            if(strncmp(str1,"1",1)==0)
            {
                QMessageBox::information(this, "Server Message", "注册成功！");
            }
            else
                QMessageBox::information(this, "Server Message", "邮箱已存在！");

            // 关闭连接
            client->write(QUIT);
        });
        this->close();

    }
    else if(checkRegister(userEmail,userPassword,userPassword2)==3)
    {
        //QMessageBox::warning(this,tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
        QMessageBox::information(this, "FlowerMail", "两次密码不一致！");
    }
    else if(checkRegister(userEmail,userPassword,userPassword2)==2)
    {
        QMessageBox::information(this, "FlowerMail", "密码长度不在6~16位！");
    }
    else
        QMessageBox::information(this, "FlowerMail", "邮件名超出20位！");

    //qDebug()<<"注册成功";

}


setup::~setup()
{
    delete ui;
}
