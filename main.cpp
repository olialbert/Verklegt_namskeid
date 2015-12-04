#include <iostream>
#include "ppInterface.h"
#include <QtSql>

using namespace std;


int main()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "computers_db.sqlite";
    QString dbProgrammers = "programmers_db.sqlite";
    db.setDatabaseName(dbName);
    db.setDatabaseName(dbProgrammers);

    db.open();
    QSqlQuery query(db);

    ppInterface ppi;

    return ppi.start();
}

