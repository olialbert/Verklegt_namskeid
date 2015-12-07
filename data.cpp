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

Programmer Data::getProgrammer(int programmerID){
    QSqlQuery query;
    string sql =  string("select * from Programmers  where programmerID=") +intToString(programmerID);
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
        sql+= string (" or birthyear like '%")+ search+ string("%' or deadyear like '%") +search+ string("%' ");
    sql +=  string(" order by ") +programmersOrderBy;
    //cout << sql << endl;
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

vector<Programmer> Data::getProgrammers(int computerID){
    vector<Programmer> programmers;
    QSqlQuery query;
    string sql =  string("SELECT p. * from Programmers p, BestOfBothWorlds bob")+
                  string(" where p.programmerID = bob.programmerID and bob.computerID =") + intToString(computerID)+
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
    query.exec(sql.c_str());
}

void Data::deleteProgrammer(int programmerID){
    QSqlQuery query;
    string sql = string("DELETE FROM Programmers WHERE ProgrammerID=") +intToString(programmerID);
    query.exec(sql.c_str());

    sql = string("DELETE FROM BestOfBothWorlds WHERE ProgrammerID=") +intToString(programmerID);
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

void Data::connectProgrammerToComputer(int computerID, int programmerID){
    QSqlQuery query;
    string sql = string("insert into BestOfBothWorlds(programmerID, computerID) values(")+intToString(programmerID)+string(", ")+intToString(computerID)+string(")");
    query.exec(sql.c_str());

}

// ********* COMPUTERS *************************************************************************

Computer Data::getComputer(int computerID) {
    QSqlQuery query;
    string sql =  string("select * from Computers where computerID=") + intToString(computerID);
    query.exec(sql.c_str());
    Computer c;


    if(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());
    }
    return c;
}

vector<Computer> Data::findComputers(string search) {
    vector<Computer> computers;
    int year = stringToInt(search);
    QSqlQuery query;
    string sql =  string("select * from Computers ");
    if (search.length()>0)
        sql +=  string(" where name like '%") +search+ string("%' or type like '%") +search+ string("%' ");
    if(year>0)
        sql+= string(" or yearbuilt like '%") +search+ string("%' ");
    sql +=  string(" order by ") +computersOrderBy;
    //cout << sql << endl;
    query.exec(sql.c_str());
    Computer c;
    while(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());

        computers.push_back(c);
    }
    return computers;
}

vector<Computer> Data::getComputers(int programmerID){
    vector<Computer> computers;
    QSqlQuery query;
    string sql =  string("SELECT c. * from Computers c, BestOfBothWorlds bob")+
                  string(" where c.computerID = bob.computerID and bob.programmerID =") + intToString(programmerID)+
                  string(" order by ") +computersOrderBy;
    query.exec(sql.c_str());
    Computer c;
    while(query.next())
    {
        c.computerID = stringToInt(query.value("computerID").toString().toStdString());
        c.Name = query.value("Name").toString().toStdString();
        c.Type = query.value("Type").toString().toStdString();
        c.WasItBuilt = query.value("WasItBuilt").toInt();
        c.YearBuilt = stringToInt(query.value("YearBuilt").toString().toStdString());

        computers.push_back(c);
    }
    return computers;
}

    // input : c - computer to be added
    // computer c as been added to the computers table
void Data::addComputer(Computer c) {
    QSqlQuery query;
    string sql = string("insert into Computers(name, type, wasitbuilt, yearbuilt) values('")+c.Name+string("','")+c.Type+string("',")+intToString(c.WasItBuilt)+string(",")+intToString(c.YearBuilt)+string(")");
    query.exec(sql.c_str());
    cout << sql << endl;
}

    // input : computerId - Id of the computer to be deleted
    // computer with Id, computerId has been deleted from the computers table
void Data::deleteComputer(int computerID) {
    QSqlQuery query;
    string sql = string("DELETE FROM Computers WHERE computerID=") +intToString(computerID);
    query.exec(sql.c_str());
    sql = string("DELETE FROM BestOfBothWorlds WHERE computerID=") +intToString(computerID);
    query.exec(sql.c_str());
}

    // input : order - sort order
    // sets the display order for the selected computers
void Data::orderComputersBy(string order) {

}

