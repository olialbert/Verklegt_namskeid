#include "data.h"
#include "utilities/constants.h"
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
    computersOrderBy = "computerID";
    programmersOrderBy = "programmerID";
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName =  QString(DATABASE_FILE_NAME.c_str());
    mydb.setDatabaseName(dbName);
    mydb.open();

    //loadDB("Name");
}


Data::~Data() {
    mydb.close();
}


// ********* PROGRAMMERS *************************************************************************

Programmer Data::getProgrammer(int programmerId){
    QSqlQuery query;
    string sql =  "select * from Programmers  where ID=";
    sql.append(intToString(programmerId));
    query.exec(sql.c_str());
    Programmer p;


    if(query.next())
    {
        p.programmerID = stringToInt(query.value("programmerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());
    }
    return p;
}

vector<Programmer> Data::findProgrammers(string search){
    vector<Programmer> programmers;
    int year = stringToInt(search);
    QSqlQuery query;
    string sql =  string("select * from Programmers ");
    if (search.length()>0)
        sql +=  string(" where name like '%") +search+ string("%' or gender like '%") +search+ string("%'");//
    if(year>0)
        sql+= string (" or birthyear =")+ search+ string(" or deadyear =") +search+ string(" ");
    sql +=  string(" order by ") +programmersOrderBy;

    cout << sql << endl; // TODO remove

    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.programmerID = stringToInt(query.value("programmerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

vector<Programmer> Data::getProgrammers(int computerId){
    vector<Programmer> programmers;
    QSqlQuery query;
    string sql =  string("SELECT p. * from Programmers p, BestOfBothWorlds bob")+
                  string(" where p.programmerID = bob.programmerID and bob.computerID =") + intToString(computerId)+
                  string(" order by ") +programmersOrderBy;
    query.exec(sql.c_str());
    Programmer p;
    while(query.next())
    {
        p.programmerID =  stringToInt(query.value("ProgrammerID").toString().toStdString());
        p.Name = query.value("Name").toString().toStdString();
        p.Gender = stringToGender(query.value("Gender").toString().toStdString());
        p.BirthYear = stringToInt(query.value("BirthYear").toString().toStdString());
        p.DeadYear = stringToInt(query.value("DeadYear").toString().toStdString());

        programmers.push_back(p);
    }
    return programmers;
}

void Data::addProgrammer(Programmer p){
    QSqlQuery query;
    string sql = string("insert into Programmers(name, gender, birthyear, deadyear) values('")+p.Name+string("','")+p.Gender+string("',")+intToString(p.BirthYear)+string(",")+intToString(p.DeadYear)+string(")");
       cout << sql << endl; // TODO remove
    query.exec(sql.c_str());
}

void Data::deleteProgrammer(int programmerID){
    QSqlQuery query;
    string sql = string("DELETE FROM Programmers WHERE ProgrammerID=") +intToString(programmerID);
    cout << sql << endl; // TODO remove
    query.exec(sql.c_str());
}

/*void Data::updateProgrammer(Programmer p){
    QSqlQuery query;
    string sql = "UPDATE Customers SET Name ='Ada Lovelace', Gender = 'Female', BirthYear = '', DeadYear = ''  WHERE ProgrammerID=" + p.
    query.exec(sql.c_str());
}*/

void Data::orderProgrammersBy(string order){
    programmersOrderBy = order;
}

// ********* COMPUTERS *************************************************************************

Computer Data::getComputer(int computerID) {
    Computer c;
    return c;
}

vector<Computer> Data::findComputer(string search) {
    vector<Computer> c;
    return c;
}

vector<Computer> Data::getComputers(int programmerID){
    vector<Computer> c;
    return c;
}

    // input : c - computer to be added
    // computer c as been added to the computers table
void Data::addComputer(Computer p) {

}

    // input : computerId - Id of the computer to be deleted
    // computer with Id, computerId has been deleted from the computers table
void Data::deleteComputer(int computerID) {
}

    // input : order - sort order
    // sets the display order for the selected computers
void Data::orderComputersBy(string order) {

}

//*************************************************************************************


/*
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
*/
