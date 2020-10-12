/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

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

class Ui_setup
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *LineEmail;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *LinePassword;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *linePassword2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *registerImmeButton;
    QSpacerItem *horizontalSpacer_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *setup)
    {
        if (setup->objectName().isEmpty())
            setup->setObjectName(QString::fromUtf8("setup"));
        setup->resize(800, 600);
        centralwidget = new QWidget(setup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 87 16pt \"Arial Black\";\n"
""));

        verticalLayout->addWidget(label);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        verticalLayout_3->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"\n"
""));

        horizontalLayout->addWidget(label_2);

        LineEmail = new QLineEdit(widget_2);
        LineEmail->setObjectName(QString::fromUtf8("LineEmail"));

        horizontalLayout->addWidget(LineEmail);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout_3->addWidget(widget_2);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
""));

        horizontalLayout_3->addWidget(label_4);

        LinePassword = new QLineEdit(widget_4);
        LinePassword->setObjectName(QString::fromUtf8("LinePassword"));
        LinePassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_3->addWidget(LinePassword);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_4);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
""));

        horizontalLayout_2->addWidget(label_3);

        linePassword2 = new QLineEdit(widget_3);
        linePassword2->setObjectName(QString::fromUtf8("linePassword2"));
        linePassword2->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_2->addWidget(linePassword2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(widget_3);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        registerImmeButton = new QPushButton(widget_5);
        registerImmeButton->setObjectName(QString::fromUtf8("registerImmeButton"));
        registerImmeButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        horizontalLayout_4->addWidget(registerImmeButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(widget_5);

        setup->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(setup);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        setup->setStatusBar(statusbar);

        retranslateUi(setup);

        QMetaObject::connectSlotsByName(setup);
    } // setupUi

    void retranslateUi(QMainWindow *setup)
    {
        setup->setWindowTitle(QCoreApplication::translate("setup", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("setup", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("setup", " \351\202\256 \347\256\261   \357\274\232  ", nullptr));
        label_4->setText(QCoreApplication::translate("setup", " \345\257\206 \347\240\201   \357\274\232  ", nullptr));
        label_3->setText(QCoreApplication::translate("setup", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        registerImmeButton->setText(QCoreApplication::translate("setup", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setup: public Ui_setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
