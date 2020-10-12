#include "login.h"
#include "ui_login.h"
#include "sendmailpro.h"
#include"client.h"
#include <QPainter>
#include<QMessageBox>
#include <QtNetwork>
#include <QString>
QString global_user_addr;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);//固定登录界面窗体大小
    this->setWindowIcon(QIcon(":/psources/sketch.jpg"));//设置窗体小图标
    this->setWindowTitle("FlowerMail登录");//设置窗体标题
    connect(ui->registerButton, SIGNAL(clicked(bool)),this,SLOT(registerButtonClicked()));//注册按钮触发事件
    connect(ui->loginButton,SIGNAL(clicked(bool)),this,SLOT(loginButtonClicked()));//登录按钮触发事件
}

//重写绘事件设置背景图片
void login::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/psources/silk.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

//点击注册按钮操作
void login::registerButtonClicked()
{
    //this->close();
    view = new setup(this);  //生成新的注册界面
    view->show();
}

//点击登录按钮操作
void login::loginButtonClicked()
{
    QString user_id2=ui->LIneEmail->text();  //记录登录账号的邮箱
    //this->close();//关闭登录界面
    //view1= new SendMailPro(0,user_id2,this); //用重载后的构造函数生成新的发送邮件主界面
    //view1->show();

    QTcpSocket *client; //socket句柄
    struct  st_mail userLogin;   //初始化结构体

    memset(&userLogin,0,sizeof (userLogin));



    QString userEmail = ui->LIneEmail->text();     //读到邮箱和密码
    QString userPassword = ui->LinePassword->text();

    //转换Qstring为普通字符串
    global_user_addr =  ui->LIneEmail->text();
    strcpy(userLogin.addr,userEmail.toUtf8().data());
    strcpy(userLogin.pwd,userPassword.toUtf8().data());
    strcpy(userLogin.operation,SIGN);

    //连接服务器
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(IP), PORT);
    client->write((char *)&userLogin,1024);

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {

        // 获取对方发送的内容
        QByteArray array = client->readAll();
        QString str = array;
        char str1[10];
        strcpy(str1,str.toUtf8().data());

        if(strncmp(str1,"1",1)==0){
            QString user_id2=ui->LIneEmail->text();
            //this->close();
            view1= new SendMailPro(0,user_id2,this);
            view1->show();
        }else{

             QMessageBox::information(this, "Server Message", "登录失败！");
             ui->LIneEmail->clear();
             ui->LinePassword->clear();
             ui->LIneEmail->setFocus();

        }

        // 关闭连接
        client->write(QUIT);
    });
}


login::~login()
{
    delete ui;
}


