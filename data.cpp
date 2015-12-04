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

    loadDB("name");
}
Data::~Data() {
    mydb.close();
}

Programmer Data::get(int nr) {
    return programmers[nr];
}

int Data::size(){
    return programmers.size();
}

void Data::add(Programmer p) {
    QSqlQuery query;
    string sql = "insert into programmers (id, name, gender, birthyear, deadyear) values ((select max(id)+1 from programmers),  '"+p.Name+"','"+p.Gender+"',"+intToString(p.BirthYear)+","+intToString(p.DeadYear)+")";
    query.exec(sql.c_str());

    programmers.push_back(p);
}

void Data::del(int nr) {
    programmers.erase(programmers.begin()+(nr-1));
}

void Data::sortByName(){
    loadDB("name");
    //sort(programmers.begin(), programmers.end(), ScientistComparator(COLUMN_NAME, true));
}

void Data::sortByGender(){
    loadDB("gender, name");
    //sortByName();
    //sort(programmers.begin(), programmers.end(), ScientistComparator(COLUMN_GENDER, true));
}

void Data::save() {
   ofstream output;
   output.open("Programmers.txt");
     if(output.fail()){
        cout << "error" << endl;
        return;
    }
    for (int i=0; i<size();i++) {
        output << get(i).Name << ";" <<  get(i).Gender << ";" <<  get(i).BirthYear << ";" <<  get(i).DeadYear << ";" << endl;
    }
    output.close();
}


void Data::load() {
    ifstream pFile;
    pFile.open("Programmers.txt");
    if(pFile.fail()){
        cout << "error" << endl;
        return;
    }
    Programmer p;
    string line;
    while (getline(pFile, line)) {
        p.Name = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.Gender = stringToGender(line.substr(0,line.find(";")));
        line = line.substr(line.find(";")+1);
        p.BirthYear = stringToInt(line.substr(0,line.find(";")));
        line = line.substr(line.find(";")+1);
        p.DeadYear = stringToInt(line.substr(0,line.find(";")));
        line = line.substr(line.find(";")+1);

        add(p);
    }
    pFile.close();
}

void Data::loadDB(string sort){
        QSqlQuery query;
        string sql =  "select * from programmers order by ";
        sql.append(sort);
        query.exec(sql.c_str());
        Programmer p;
        programmers.clear();
        while(query.next())
        {
            p.Name = query.value("name").toString().toStdString();
            p.Gender = stringToGender(query.value("gender").toString().toStdString());
            p.BirthYear = stringToInt(query.value("birthyear").toString().toStdString());
            p.DeadYear = stringToInt(query.value("deadyear").toString().toStdString());

            programmers.push_back(p);
        }
}
