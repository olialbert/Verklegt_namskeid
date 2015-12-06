#include "data.h"
#include "utilities/constants.h"
#include "utilities/scientistcomparator.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <stdio.h>
#include <string>

using namespace constants;
using namespace utils;


Data::Data() {
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName =  QString(DATABASE_FILE_NAME.c_str());
    mydb.setDatabaseName(dbName);
    mydb.open();

    loadDB("Name");
    mydb.close();
}


Data::~Data() {
    mydb.close();
}

Data();
~Data();

// ********* PROGRAMMERS *************************************************************************

Programmer getProgrammer(int programmerId){
    QSqlQuery query;
    string sql =  "select * from Programmers  where ID=";
    sql.append(intToString(programmerId));
    query.exec(sql.c_str());
    Programmer p;


    if(query.next())
    {
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());
    }
    return p;
}

vector<Programmer> findProgrammers(string search){
    vector<Programmer> programmers;
    QSqlQuery query;
    string sql =  "select * from Programmers " +
                  " where name like '%" +search+ "%' or gender like '%" +search+ "%' or birthyear '%" +search+ "%' or deadyear '%" +search+ "%' "
                  " order by " +programmersOrderBy;
    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

vector<Programmer> getProgrammers(int computerId){
    vector<Programmer> programmers;
    QSqlQuery query;
    string sql =  "SELECT p. * from Programmers p, BestOfBothWorlds bob"+
                  " where p.programmerID = bob.programmerID and bob.computerID =" + intToString(computerId)+
                  " order by " +programmersOrderBy;
    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.ProgrammerID =  stringToInt(query.value("ProgrammerID").toString().toStdString());          
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

void addProgrammer(Programmer p){
    QSqlQuery query;
    string sql = "insert into programmers (id, name, gender, birthyear, deadyear) values ((select max(id)+1 from programmers),  '"+p.Name+"','"+p.Gender+"',"+intToString(p.BirthYear)+","+intToString(p.DeadYear)+")";
    query.exec(sql.c_str());

    programmers.push_back(p);
}

void delProgrammer(int programmerId){
    QSqlQuery query;
    string sql = "DELETE FROM Programmer WHERE ProgrammerID=" +programmerId;
    query.exec(sql.c_str());
}

void updateProgrammer(Programmer p){
    QSqlQuery query;
    string sql = "UPDATE Customers SET Name ='Ada Lovelace', Gender = 'Female', BirthYear = '', DeadYear = ''  WHERE ProgrammerID=" + p.
    query.exec(sql.c_str());
}

void orderProgrammersBy(string order){
    programmersOrderBy = order;
}

// ********* COMPUTERS *************************************************************************

Computer getComputer(int id);
vector<Computer> findComputer(string search);
vector<Computer> getComputers(int programmerID);

    // input : c - computer to be added
    // computer c as been added to the computers table
void addComputer(Computer p);

    // input : computerId - Id of the computer to be deleted
    // computer with Id, computerId has been deleted from the computers table
void delComputer(int computerId);

    // input : order - sort order
    // sets the display order for the selected computers
void orderComputersBy(string order);

//*************************************************************************************

void Data::del(int nr) {
    programmers.erase(programmers.begin()+(nr-1));
}

void Data::loadDB(string sort){
        QSqlQuery query;
        string sql =  "select * from Programmers order by ";
        sql.append(sort);
        query.exec(sql.c_str());
        Programmer p;
        programmers.clear();
        while(query.next())
        {
            p.Name = query.value("Name").toString().toStdString();
            p.Gender = stringToGender(query.value("Gender").toString().toStdString());
            p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
            p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

            programmers.push_back(p);
        }
}
