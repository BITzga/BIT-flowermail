#ifndef SENDMAILPRO_H
#define SENDMAILPRO_H
#include <QLabel>
#include <QMainWindow>


namespace Ui {
class SendMailPro;
}

class SendMailPro : public QMainWindow
{
    Q_OBJECT

public:
    SendMailPro *send2;
    int i_color;//控制变换背景图片的参数
    QString user_id;//登陆人用户名
    SendMailPro(int i=0,QString id=NULL,QWidget *parent = nullptr);
    ~SendMailPro();
    void paintEvent(QPaintEvent *);//重写paintEvent设置背景图片

private slots:
    void on_selectSketch_clicked();//草稿箱选择草稿文件按钮槽函数

    void on_saveSketch_2_clicked();//草稿箱保存草稿文件按钮槽函数

    void on_sendButton2_clicked();//发件箱发件按钮槽函数

    void on_exitButton_clicked();//退出按钮槽函数

    void on_deleteButton_clicked();//收件箱邮件删除按钮槽函数

    void on_updateButton_clicked();//收件箱邮件刷新按钮槽函数

    void on_choosecolorButton_clicked();//发件邮件编写页面选择字体按钮槽函数

    void on_choosesizeButton_clicked();//发件邮件编写页面选择字体颜色按钮槽函数

    void on_savesketchButton_clicked();//发件页面保存草稿按钮槽函数

    void on_transButton_clicked();//收件箱转发按钮槽函数

    void on_tableInfo_cellClicked(int row, int column);//收件箱邮件列表双击选择邮件槽函数

    void on_replyButton_clicked();//收件箱回复邮件按钮槽函数

    void on_searchButton_clicked();//收件箱邮件关键字搜索按钮槽函数

    void on_choosesizeButton_2_clicked();

private:
    Ui::SendMailPro *ui;
    QString fpath;
    bool OpenSeleteFile();//弹出选择文件对话框
    void ShowTxtToWindow();//显示txt文件内容
};

#endif // SENDMAILPRO_H
