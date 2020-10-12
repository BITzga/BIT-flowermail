#ifndef SETUP_H
#define SETUP_H

#include <QMainWindow>
namespace Ui {
class setup;
}

class setup : public QMainWindow
{
    Q_OBJECT

public:
    explicit setup(QWidget *parent = nullptr);
    ~setup();
    void paintEvent(QPaintEvent *);//重写paintEvent设置背景图片
    int checkRegister(QString email, QString pwd,QString pwd2);//检查用户注册邮箱、密码是否合格
public slots:
    void registerImmeButtonPressed();//点击注册后的槽函数

private:
    Ui::setup *ui;
};

#endif // SETUP_H
