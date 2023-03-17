#include "connection.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include "sqloperation.h"

connection::connection(QObject *parent)
    : QObject{parent}{
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setDatabaseName("mysql");
        db.setUserName("root");
        db.setPassword("12345");
        bool check = db.open();
        if(check) {
            qDebug()<<"连接成功";
        }
        else {
            qDebug()<<"连接失败"<<db.lastError().text();
        }

        sqlOperation();     //创建一次就行，已经创建了主键为id的password表

    }


}
