/********************************************************************************
** Form generated from reading UI file 'sendmailpro.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMAILPRO_H
#define UI_SENDMAILPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendMailPro
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *sendButton;
    QPushButton *getButton;
    QPushButton *sketchButton;
    QPushButton *pushButton;
    QWidget *widget_7;
    QGridLayout *gridLayout_9;
    QPushButton *exitButton;
    QLineEdit *psendEdit;
    QLabel *label_8;
    QFrame *line;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_9;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *sendEmail;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *receiveEmail;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLineEdit *Subject;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_5;
    QLineEdit *addAttachment;
    QWidget *widget_11;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *choosesizeButton_2;
    QPushButton *choosesizeButton;
    QPushButton *choosecolorButton;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QTextEdit *textEdit;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendButton2;
    QPushButton *savesketchButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_3;
    QGridLayout *gridLayout_8;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *updateButton;
    QPushButton *replyButton;
    QPushButton *transButton;
    QPushButton *deleteButton;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableInfo;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *keywordEdit;
    QPushButton *searchButton;
    QWidget *page_4;
    QGridLayout *gridLayout_7;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pathEdit;
    QPushButton *selectSketch;
    QPushButton *saveSketch_2;
    QPlainTextEdit *sketchEdit;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_3;
    QGridLayout *gridLayout_5;
    QPushButton *gtkButton;
    QPushButton *windowxpButton;
    QPushButton *windowsButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *fusionButton;
    QSpacerItem *horizontalSpacer_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SendMailPro)
    {
        if (SendMailPro->objectName().isEmpty())
            SendMailPro->setObjectName(QString::fromUtf8("SendMailPro"));
        SendMailPro->setWindowModality(Qt::ApplicationModal);
        SendMailPro->resize(724, 589);
        centralwidget = new QWidget(SendMailPro);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(140, 50));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sendButton = new QPushButton(widget_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 12pt \"Arial\";\n"
"\n"
"\n"
""));

        verticalLayout_2->addWidget(sendButton);

        getButton = new QPushButton(widget_2);
        getButton->setObjectName(QString::fromUtf8("getButton"));
        getButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 12pt \"Arial\";\n"
"\n"
"\n"
""));

        verticalLayout_2->addWidget(getButton);

        sketchButton = new QPushButton(widget_2);
        sketchButton->setObjectName(QString::fromUtf8("sketchButton"));
        sketchButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 12pt \"Arial\";\n"
"\n"
""));

        verticalLayout_2->addWidget(sketchButton);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 12pt \"Arial\";\n"
"\n"
""));

        verticalLayout_2->addWidget(pushButton);


        gridLayout_4->addWidget(widget_2, 1, 0, 1, 1);

        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy1);
        gridLayout_9 = new QGridLayout(widget_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        exitButton = new QPushButton(widget_7);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        gridLayout_9->addWidget(exitButton, 0, 4, 1, 1);

        psendEdit = new QLineEdit(widget_7);
        psendEdit->setObjectName(QString::fromUtf8("psendEdit"));

        gridLayout_9->addWidget(psendEdit, 0, 2, 1, 1);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));

        gridLayout_9->addWidget(label_8, 0, 0, 1, 1);

        line = new QFrame(widget_7);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line, 1, 0, 1, 5);

        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));

        gridLayout_9->addWidget(label_6, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_9, 0, 3, 1, 1);


        gridLayout_4->addWidget(widget_7, 0, 0, 1, 3);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_6 = new QWidget(page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_3 = new QGridLayout(widget_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 29, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 3, 1);

        widget = new QWidget(widget_6);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";\n"
""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        sendEmail = new QLineEdit(widget);
        sendEmail->setObjectName(QString::fromUtf8("sendEmail"));

        gridLayout->addWidget(sendEmail, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";\n"
""));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        receiveEmail = new QLineEdit(widget);
        receiveEmail->setObjectName(QString::fromUtf8("receiveEmail"));

        gridLayout->addWidget(receiveEmail, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";\n"
""));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        Subject = new QLineEdit(widget);
        Subject->setObjectName(QString::fromUtf8("Subject"));

        gridLayout->addWidget(Subject, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";\n"
""));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        addAttachment = new QLineEdit(widget);
        addAttachment->setObjectName(QString::fromUtf8("addAttachment"));

        gridLayout->addWidget(addAttachment, 6, 1, 1, 1);

        widget_11 = new QWidget(widget);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));

        gridLayout->addWidget(widget_11, 7, 0, 1, 1);

        widget_12 = new QWidget(widget);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_4 = new QHBoxLayout(widget_12);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        choosesizeButton_2 = new QPushButton(widget_12);
        choosesizeButton_2->setObjectName(QString::fromUtf8("choosesizeButton_2"));
        choosesizeButton_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_4->addWidget(choosesizeButton_2);

        choosesizeButton = new QPushButton(widget_12);
        choosesizeButton->setObjectName(QString::fromUtf8("choosesizeButton"));
        choosesizeButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_4->addWidget(choosesizeButton);

        choosecolorButton = new QPushButton(widget_12);
        choosecolorButton->setObjectName(QString::fromUtf8("choosecolorButton"));
        choosecolorButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_4->addWidget(choosecolorButton);


        gridLayout->addWidget(widget_12, 7, 1, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
""));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        textEdit = new QTextEdit(widget_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget_4, 2, 0, 1, 1);


        verticalLayout->addWidget(widget_6);

        widget_10 = new QWidget(page);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout = new QHBoxLayout(widget_10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        sendButton2 = new QPushButton(widget_10);
        sendButton2->setObjectName(QString::fromUtf8("sendButton2"));
        sendButton2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        horizontalLayout->addWidget(sendButton2);

        savesketchButton = new QPushButton(widget_10);
        savesketchButton->setObjectName(QString::fromUtf8("savesketchButton"));
        savesketchButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";\n"
"\n"
""));

        horizontalLayout->addWidget(savesketchButton);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_10);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_8 = new QGridLayout(page_3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        widget_9 = new QWidget(page_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_3 = new QHBoxLayout(widget_9);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        updateButton = new QPushButton(widget_9);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_3->addWidget(updateButton);

        replyButton = new QPushButton(widget_9);
        replyButton->setObjectName(QString::fromUtf8("replyButton"));
        replyButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_3->addWidget(replyButton);

        transButton = new QPushButton(widget_9);
        transButton->setObjectName(QString::fromUtf8("transButton"));
        transButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_3->addWidget(transButton);

        deleteButton = new QPushButton(widget_9);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_3->addWidget(deleteButton);


        gridLayout_8->addWidget(widget_9, 0, 0, 1, 1);

        widget_8 = new QWidget(page_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_4 = new QVBoxLayout(widget_8);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableInfo = new QTableWidget(widget_8);
        tableInfo->setObjectName(QString::fromUtf8("tableInfo"));

        verticalLayout_4->addWidget(tableInfo);


        gridLayout_8->addWidget(widget_8, 2, 0, 1, 1);

        widget_13 = new QWidget(page_3);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_5 = new QHBoxLayout(widget_13);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        keywordEdit = new QLineEdit(widget_13);
        keywordEdit->setObjectName(QString::fromUtf8("keywordEdit"));

        horizontalLayout_5->addWidget(keywordEdit);

        searchButton = new QPushButton(widget_13);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_5->addWidget(searchButton);


        gridLayout_8->addWidget(widget_13, 1, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_7 = new QGridLayout(page_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget_5 = new QWidget(page_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pathEdit = new QLineEdit(widget_5);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        horizontalLayout_2->addWidget(pathEdit);

        selectSketch = new QPushButton(widget_5);
        selectSketch->setObjectName(QString::fromUtf8("selectSketch"));
        selectSketch->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_2->addWidget(selectSketch);

        saveSketch_2 = new QPushButton(widget_5);
        saveSketch_2->setObjectName(QString::fromUtf8("saveSketch_2"));
        saveSketch_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(95, 95, 95, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_2->addWidget(saveSketch_2);


        gridLayout_7->addWidget(widget_5, 0, 0, 1, 1);

        sketchEdit = new QPlainTextEdit(page_4);
        sketchEdit->setObjectName(QString::fromUtf8("sketchEdit"));

        gridLayout_7->addWidget(sketchEdit, 1, 0, 1, 1);

        stackedWidget->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        widget_3 = new QWidget(page_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_5 = new QGridLayout(widget_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gtkButton = new QPushButton(widget_3);
        gtkButton->setObjectName(QString::fromUtf8("gtkButton"));
        gtkButton->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(59, 100, 151, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_5->addWidget(gtkButton, 1, 0, 1, 1);

        windowxpButton = new QPushButton(widget_3);
        windowxpButton->setObjectName(QString::fromUtf8("windowxpButton"));
        windowxpButton->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(59, 100, 151, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_5->addWidget(windowxpButton, 1, 2, 1, 1);

        windowsButton = new QPushButton(widget_3);
        windowsButton->setObjectName(QString::fromUtf8("windowsButton"));
        windowsButton->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(59, 100, 151, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_5->addWidget(windowsButton, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 1, 2, 1);

        fusionButton = new QPushButton(widget_3);
        fusionButton->setObjectName(QString::fromUtf8("fusionButton"));
        fusionButton->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(59, 100, 151, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_5->addWidget(fusionButton, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_3, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_4->addWidget(stackedWidget, 1, 1, 2, 2);

        SendMailPro->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SendMailPro);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SendMailPro->setStatusBar(statusbar);

        retranslateUi(SendMailPro);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SendMailPro);
    } // setupUi

    void retranslateUi(QMainWindow *SendMailPro)
    {
        SendMailPro->setWindowTitle(QCoreApplication::translate("SendMailPro", "MainWindow", nullptr));
        sendButton->setText(QCoreApplication::translate("SendMailPro", "\345\217\221\344\273\266", nullptr));
        getButton->setText(QCoreApplication::translate("SendMailPro", "\346\224\266\344\273\266\347\256\261", nullptr));
        sketchButton->setText(QCoreApplication::translate("SendMailPro", "\350\215\211\347\250\277\347\256\261", nullptr));
        pushButton->setText(QCoreApplication::translate("SendMailPro", "\351\200\211\346\213\251\344\270\273\351\242\230", nullptr));
        exitButton->setText(QCoreApplication::translate("SendMailPro", "\351\200\200\345\207\272", nullptr));
        label_8->setText(QCoreApplication::translate("SendMailPro", "FlowerMail", nullptr));
        label_6->setText(QCoreApplication::translate("SendMailPro", "\346\234\254\344\272\272\351\202\256\347\256\261\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SendMailPro", "\345\217\221\344\273\266\344\272\272 ", nullptr));
        label_2->setText(QCoreApplication::translate("SendMailPro", "\346\224\266\344\273\266\344\272\272", nullptr));
        label_3->setText(QCoreApplication::translate("SendMailPro", "\344\270\273\351\242\230", nullptr));
        label_5->setText(QCoreApplication::translate("SendMailPro", "\346\267\273\345\212\240\351\231\204\344\273\266", nullptr));
        choosesizeButton_2->setText(QCoreApplication::translate("SendMailPro", "\346\267\273\345\212\240\351\231\204\344\273\266", nullptr));
        choosesizeButton->setText(QCoreApplication::translate("SendMailPro", "\351\200\211\346\213\251\345\255\227\344\275\223", nullptr));
        choosecolorButton->setText(QCoreApplication::translate("SendMailPro", "\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
        label_4->setText(QCoreApplication::translate("SendMailPro", "\346\255\243\346\226\207      ", nullptr));
        sendButton2->setText(QCoreApplication::translate("SendMailPro", "\345\217\221\351\200\201", nullptr));
        savesketchButton->setText(QCoreApplication::translate("SendMailPro", "\345\255\230\350\215\211\347\250\277", nullptr));
        updateButton->setText(QCoreApplication::translate("SendMailPro", "\345\210\267\346\226\260", nullptr));
        replyButton->setText(QCoreApplication::translate("SendMailPro", "\345\233\236\345\244\215", nullptr));
        transButton->setText(QCoreApplication::translate("SendMailPro", "\350\275\254\345\217\221", nullptr));
        deleteButton->setText(QCoreApplication::translate("SendMailPro", "\345\210\240\351\231\244", nullptr));
        searchButton->setText(QCoreApplication::translate("SendMailPro", "\346\237\245\346\211\276", nullptr));
        selectSketch->setText(QCoreApplication::translate("SendMailPro", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        saveSketch_2->setText(QCoreApplication::translate("SendMailPro", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        gtkButton->setText(QCoreApplication::translate("SendMailPro", "grey", nullptr));
        windowxpButton->setText(QCoreApplication::translate("SendMailPro", "silver", nullptr));
        windowsButton->setText(QCoreApplication::translate("SendMailPro", "pink", nullptr));
        fusionButton->setText(QCoreApplication::translate("SendMailPro", "skyblue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendMailPro: public Ui_SendMailPro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMAILPRO_H
