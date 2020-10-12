#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "setup.h"
#include"client.h"
#include "sendmailpro.h" //加需要跳转到的界面的.h文件
#include<QString>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void paintEvent(QPaintEvent *);//重写paintEvent设置背景图片

public slots://5.4版本以后槽函数可以写到public或全局函数
    void registerButtonClicked();//点击注册后的槽函数，可以有参数可以发生重载
    void loginButtonClicked();//点击登录后的槽函数
private slots:

private:
    Ui::login *ui;
    setup *view;//创建注册类的指针
    SendMailPro *view1; //创建指向写信界面的指针
};


#endif // LOGIN_H
