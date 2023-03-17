#include "sqloperation.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

sqlOperation::sqlOperation()
{
    QSqlQuery query;
//    QString sql1 = "create table password(id int primary key, password varchar(255));";
//    bool passwordTableCreate =  query.exec(sql1);
//    if(passwordTableCreate) {
//        qDebug()<<"创建成功";
//    }
//    else qDebug()<<"创建失败";

    QString sql2 = "insert into password(id, password) values ('123','123')";
    bool insertDefaltPassword = query.exec(sql2);
    if(insertDefaltPassword) {
        qDebug()<<"插入测试用户成功";
    }
    else  qDebug()<<"插入测试用户失败";


}
