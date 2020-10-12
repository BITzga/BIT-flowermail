#include "sendmailpro.h"
#include "ui_sendmailpro.h"
#include "login.h"
#include "client.h"
#include <QPushButton>
#include <QPainter>
#include <QStyleFactory>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <cstring>
#include <QtNetwork>
#include <QTableWidget>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
extern QString global_user_addr;

SendMailPro::SendMailPro(int i,QString id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SendMailPro)
{
    i_color=i;//选择背景图片编号
    user_id=id;//设置登陆人用户名
    ui->setupUi(this);
    this->resize(1000,800);
    this->setWindowIcon(QIcon(":/psources/sketch.jpg"));
    this->setWindowTitle("FlowerMail");
    ui->psendEdit->setReadOnly(true); //用户本人邮箱展示不可编辑
    ui->sendEmail->setReadOnly(true);
    ui->psendEdit->setText(user_id);
    ui->sendEmail->setText(user_id);
     ui->stackedWidget->setCurrentIndex(0);

    //写件按钮
    connect(ui->sendButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //收件按钮
    connect(ui->getButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //草稿箱按钮
    connect(ui->sketchButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    //主题按钮
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
      //blue主题
    connect(ui->fusionButton,&QPushButton::clicked,[=]()
    {
        QString id2=this->user_id;
        this->close();
        send2=new SendMailPro(1,id2,this);
        send2->show();
    });
      //pink主题
    connect(ui->windowsButton,&QPushButton::clicked,[=](){
        QString id2=this->user_id;
        this->close();
        send2=new SendMailPro(2,id2,this);
        send2->show();
    });
      //silver主题
    connect(ui->windowxpButton,&QPushButton::clicked,[=](){
        QString id2=this->user_id;
        this->close();
        send2=new SendMailPro(3,id2,this);
        send2->show();
    });
      //原grey主题
    connect(ui->gtkButton,&QPushButton::clicked,[=](){
        QString id2=this->user_id;
        this->close();
        send2=new SendMailPro(0,id2,this);
        send2->show();
    });
    //收件箱
      //收件表格设置
    ui->tableInfo->setColumnCount(3);
    ui->tableInfo->setHorizontalHeaderLabels(QStringList()<<tr("发件人")<<tr("主题")<<tr("正文"));//设置表头
    ui->tableInfo->setAlternatingRowColors(true);
    ui->tableInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableInfo->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:silver;font:13pt '宋体'}");
    ui->tableInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
      //插入收件信息
    /*int row=ui->tableInfo->rowCount(); //当前总行数
    ui->tableInfo->insertRow(row);
    ui->tableInfo->setItem(row,0,new QTableWidgetItem("JanfqUqJHBSDFGHJKL;FMNSUAHVCADJGVIAKJHSDJDHDDXH"));
    ui->tableInfo->setItem(row,1,new QTableWidgetItem("JanfqUqJHBSDFGHJKL;FMNSUAHVCADJGVIAKJHSDJDHDDXH"));
    ui->tableInfo->setItem(row,2,new QTableWidgetItem("JanfqUqJHBSDFGHJKL;FMNSUAHVCADJGVIAKJHSDJDHDDXH"));
*/
}


//重写绘图事件设置背景图片
void SendMailPro::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    if(i_color==0)
    {
        pix.load(":/psources/silk.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
    else if(i_color==1)
    {
        pix.load(":/psources/blue.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
    else if(i_color==2)
    {
        pix.load(":/psources/ppink.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
    else if(i_color==3)
    {
        pix.load(":/psources/cloud.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }

}


SendMailPro::~SendMailPro()
{
    delete ui;
}

//草稿箱选择文件操作
void SendMailPro::on_selectSketch_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"打开文件","D:\\Qtt\\fmail");
    ui->pathEdit->setText(path);
    QFile file(path);
    fpath=path;
    //读操作
    file.open(QIODevice::ReadOnly);
    QByteArray array=file.readAll();
    ui->sketchEdit->setPlainText(array);
    file.close();
}

//草稿箱保存文件操作
void SendMailPro::on_saveSketch_2_clicked()
{
    QFile myfile(fpath);//创建一个输出文件的文档
        if (myfile.open(QFile::WriteOnly|QFile::Text))
        {
            QTextStream out(&myfile);
            out << ui->sketchEdit->toPlainText();
        }
        ShowTxtToWindow();

}

//显示文本文件中的内容
void SendMailPro::ShowTxtToWindow()
{
    QString fileName = fpath;

    if(!fileName.isEmpty())
    {
        QFile *file = new QFile;
        file->setFileName(fileName);
        bool ok = file->open(QIODevice::ReadOnly);
        if(ok)
        {
            QTextStream in(file);
            ui->sketchEdit->setPlainText(in.readAll());
            file->close();
            delete file;
        }
    }
}

//发件箱发送邮件操作
void SendMailPro::on_sendButton2_clicked()
{

    QTcpSocket *client; //socket句柄
    struct st_mail mail;
    memset(&mail,0,sizeof (mail));


    //用qstring读取文本框
    QString buf_addr = ui->sendEmail->text();
    QString buf_title = ui->Subject->text();
    QString buf_content = ui->textEdit->toPlainText();
    QString buf_recv_addr = ui->receiveEmail->text();

    //转换Qstring为普通字符串
    strcpy(mail.addr,buf_addr.toUtf8().data());
    strcpy(mail.title,buf_title.toUtf8().data());
    strcpy(mail.content,buf_content.toUtf8().data());
    strcpy(mail.toaddr,buf_recv_addr.toUtf8().data());
    strcpy(mail.operation,"SEND");

    //连接服务器
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(IP), 8080);
    client->write((char *)&mail,1024);

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {

        // 获取对方发送的内容
        char str1[2];
        client->read(str1,1);

        if(strncmp(str1,"1",1)==0){

             ui->receiveEmail->clear();
             ui->Subject->clear();
             ui->textEdit->clear();
             ui->receiveEmail->setFocus();
             QMessageBox::information(this, "Server Message", "发送成功！");

        }else{

             QMessageBox::information(this, "Server Message", "发送失败！");
        }
        // 关闭连接
        client->write(QUIT);
    });

}

//退出界面
void SendMailPro::on_exitButton_clicked()
{
    this->close();
}

//收件箱邮件列表删除选中邮件操作
void SendMailPro::on_deleteButton_clicked()
{
    int rowIndex= ui->tableInfo->currentRow();
    if(rowIndex!=-1)
    {
        ui->tableInfo->removeRow(rowIndex);
    }
    QMessageBox::information(this,tr("FlowerMail"),tr("删除成功！"));
}

//收件箱刷新获得未读邮件操作
void SendMailPro::on_updateButton_clicked()
{

    //连接服务器

    QTcpSocket *client; //socket句柄
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(IP), PORT);
    st_mail mail;


    // 发送请求到服务器
    strcpy(mail.addr,global_user_addr.toUtf8().data());
    strcpy(mail.operation, RECEIVE);
    client->write((char *)&mail, sizeof(st_mail));

    // 获取服务器处理结果
    connect(client, &QTcpSocket::readyRead, [=]()
    {
        char buffer[20484];
        struct st_mail_list list;
        memset(&list, 0, sizeof(st_mail_list));
        memset(buffer,0, 20484);



            client->read(buffer,20484);

            memcpy(&list, buffer, sizeof(struct st_mail_list));

            // 获取对方发送的内容
        for(int i=0;i<list.sum;i++){

            int row=ui->tableInfo->rowCount(); //当前总行数
            ui->tableInfo->insertRow(row);
            ui->tableInfo->setItem(row,0,new QTableWidgetItem(list.mails[i].addr));
            ui->tableInfo->setItem(row,1,new QTableWidgetItem(list.mails[i].title));
            ui->tableInfo->setItem(row,2,new QTableWidgetItem(list.mails[i].content));
        }

        // 关闭连接
        client->write(QUIT);

    });



}

//发件页面邮件正文选择字体颜色操作
void SendMailPro::on_choosecolorButton_clicked()
{
    QPalette pal=ui->textEdit->palette();  //获取文本框的palette
           QColor iniColor=pal.color(QPalette::Text);   //现有的文字的颜色
           QColor color=QColorDialog::getColor(iniColor,this,"选择颜色");
           if(color.isValid())//如果颜色是可用的
           {
               pal.setColor(QPalette::Text,color);//设置QPalette对象
               ui->textEdit->setPalette(pal);//设置文本框颜色
            }
}


//发件页面选择邮件正文字体格式操作
void SendMailPro::on_choosesizeButton_clicked()
{
    QFont iniFont=ui->textEdit->font();//获取文本框字体
            bool ok=false;
            QFont font=QFontDialog::getFont(&ok,iniFont);
            if(ok)
                ui->textEdit->setFont(font);

}

//发件箱保存草稿操作
void SendMailPro::on_savesketchButton_clicked()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Open File"),"D:/Qtt",tr("Text File(*.txt)"));
    if(fileName == "")
    {
        return;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))//打开文件失败
    {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
        return;
    }
    else //成功打开文件并保存
    {
        QTextStream textStream(&file);
        QString str = ui->textEdit->toPlainText();
        textStream<<str;
        QMessageBox::warning(this,tr("提示"),tr("保存文件成功"));

        file.close();
    }
}

//收件箱转发选中邮件操作
void SendMailPro::on_transButton_clicked()
{
    int rowIndex2= ui->tableInfo->currentRow();
    if(rowIndex2!=-1)
    {
        QString subjectItem=ui->tableInfo->item(rowIndex2,1)->text();
        QString textItem=ui->tableInfo->item(rowIndex2,2)->text();
        ui->stackedWidget->setCurrentIndex(0);//跳转到发件页面
        ui->Subject->setText(subjectItem);//自动填写邮件主题与正文
        ui->textEdit->setText(textItem);
    }
}

//收件箱单击列表表格，用弹窗显示当前表格完整内容
void SendMailPro::on_tableInfo_cellClicked(int row, int column)
{
    QString emailContent;
    emailContent= ui->tableInfo->item(row,column)->text();
    QMessageBox::information(this,"FlowerMail", emailContent.toUtf8().data());

}

//收件箱回复选中邮件操作
void SendMailPro::on_replyButton_clicked()
{
    int rowIndex3= ui->tableInfo->currentRow();
    if(rowIndex3!=-1)
    {
        QString receiveItem=ui->tableInfo->item(rowIndex3,0)->text();
        ui->stackedWidget->setCurrentIndex(0);//跳转到发件页面
        ui->receiveEmail->setText(receiveItem);//自动填写收件人地址
    }
}

//收件箱按关键字搜索相关邮件
void SendMailPro::on_searchButton_clicked()
{
    QString keyword=ui->keywordEdit->text();
    QString str;
    int flag=0;
    int num_row=ui->tableInfo->rowCount();
    for(int i=0;i<num_row;i++)//遍历搜索正文含有关键字的邮件
    {
        str=ui->tableInfo->item(i,2)->text();
        if(str.contains(keyword))
        {
            QMessageBox::information(this,"相关邮件",QString("发件人")+QString("<br>")+ui->tableInfo->item(i,0)->text()+QString("<br>")
                                     +QString("主题")+QString("<br>")+ui->tableInfo->item(i,1)->text()+QString("<br>")+QString("正文")+QString("<br>")+ui->tableInfo->item(i,2)->text());
            flag=1;
        }
    }
    if(flag==0)//未搜索到符合条件的邮件
    {
        QMessageBox::warning(this,"相关邮件",QString("Not Found!"));
    }
}

void SendMailPro::on_choosesizeButton_2_clicked()
{
    //连接服务器

    QTcpSocket *client; //socket句柄
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(IP), PORT);

    QString file, file_name, file_path;
    QFileInfo fi;
    file= QFileDialog::getOpenFileName(this);  // 这一行获取的是文件选择框选择之后的完整路径加文件名
    fi = QFileInfo(file);
    file_name = fi.fileName();  //获取文件名
    file_path = fi.absolutePath(); //获取文件路径(不包含文件名)
    char b[64];
     char a[128];
    QString total = file_path +"/"+file_name;
    strcpy(b,total.toUtf8().data());
    int i,j=0;
    for(i=0,j=0;i<128;i++,j++){

        if(b[i]=='/'){
            a[j] ='\\';
            j++;
            a[j] ='\\';

        }
        else{
            a[j] =b[i];
        }
    }

    int len;
    struct filehelp cfile;
    FILE *src_fp;

    QMessageBox::information(this,"FlowerMail","发送附件成功！");

    if ((src_fp = fopen(a, "rb+")) == NULL)
    {
        printf("fopen %s failed./n",a);
        exit(0);
    }
    while((len = fread(cfile.file, sizeof(char), 768, src_fp)) > 0){
           strncpy(cfile.operation,"DATA",4);
           strcpy (cfile.file_name,a);
           client->write((char *)&cfile, 1024);

    }
    client->write(QUIT);

    fclose(src_fp);

}
