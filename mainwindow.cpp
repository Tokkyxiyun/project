#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LogIn_clicked()
{
    int id = ui->lineid->text().toInt();
    QString psw = ui->linepassword->text();
    QSqlQuery query;
    QString sql1 = QString("select id from password where id = '%1' ").arg(id);
    query.exec(sql1);
    query.next();
    bool IsIdExsist = (query.value(0).toInt() == id);
    if(!IsIdExsist) {
        QMessageBox::warning(this, "error", "用户不存在");
    }
    else {
        QString sql2 = QString("select password from password where id = '%1'").arg(id);
        query.exec(sql2);
        query.next();
        bool IsPasswordCorrect = (query.value(0).toString() == psw);
        if(!IsPasswordCorrect) {
            QMessageBox::warning(this, "error", "密码错误");
        }
        else QMessageBox::information(this, "success", "登录成功");
    }
}

