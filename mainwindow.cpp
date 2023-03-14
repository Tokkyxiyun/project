#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);

    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);

    });
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);

    });
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

