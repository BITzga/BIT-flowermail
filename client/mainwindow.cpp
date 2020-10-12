#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include <QComboBox>
#include <QStyleFactory>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

