#include "mainwindow.h"
#include "login.h"
#include "setup.h"
#include"client.h"
#include "sendmailpro.h"
#include <QApplication>
#include <QString>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login log_in;

    log_in.show();
//    SendMailPro s;
//    s.show();
    return a.exec();
}
