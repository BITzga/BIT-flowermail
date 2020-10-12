/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label2;
    QLineEdit *LIneEmail;
    QSpacerItem *horizontalSpacer3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *LinePassword;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer5;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font: 87 16pt \"Arial Black\";\n"
""));

        verticalLayout->addWidget(label_3);

        line = new QFrame(widget_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        verticalLayout_2->addWidget(widget_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label2 = new QLabel(widget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
""));

        horizontalLayout->addWidget(label2);

        LIneEmail = new QLineEdit(widget);
        LIneEmail->setObjectName(QString::fromUtf8("LIneEmail"));

        horizontalLayout->addWidget(LIneEmail);

        horizontalSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer3);


        verticalLayout_2->addWidget(widget);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
""));

        horizontalLayout_3->addWidget(label);

        LinePassword = new QLineEdit(widget_4);
        LinePassword->setObjectName(QString::fromUtf8("LinePassword"));
        LinePassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(LinePassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_4);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer5);

        registerButton = new QPushButton(widget2);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        horizontalLayout_2->addWidget(registerButton);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        loginButton = new QPushButton(widget2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        horizontalLayout_2->addWidget(loginButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget2);

        login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        label2->setText(QCoreApplication::translate("login", "\351\202\256\347\256\261\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("login", "\345\257\206\347\240\201\357\274\232", nullptr));
        registerButton->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        loginButton->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
