#include "Programmers.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

bool compare_name (Programmer first, Programmer second) // nocase
{
  unsigned int i=0;
  while ( (i<first.Name.length()) && (i<second.Name.length()) )
  {
    if (tolower(first.Name[i])<tolower(second.Name[i])) return true;
    else if (tolower(first.Name[i])>tolower(second.Name[i])) return false;
    ++i;
  }
  return ( first.Name.length() < second.Name.length() );
}
bool compare_gender(Programmer first, Programmer second) // nocase
{
  unsigned int i=0;
  while ( (i<first.Gender.length()) && (i<second.Gender.length()) )
  {
    if (tolower(first.Gender[i])<tolower(second.Gender[i])) return true;
    else if (tolower(first.Gender[i])>tolower(second.Gender[i])) return false;
    ++i;
  }
  return ( first.Gender.length() < second.Gender.length() );
}

Programmers::Programmers() {
    load();
}
// loads all scientists from text file
// format name;gender;BirthYear
void Programmers::load() {
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
        p.Gender = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.BirthYear = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.DeadYear = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);

        add(p);
    }
    pFile.close();
}
void Programmers::save() {
   ofstream output;
   output.open("Programmers.txt");
     if(output.fail()){
        cout << "error" << endl;
        return;
    }
    for (unsigned int i=0; i<size();i++) {
        output << getProgrammer(i).Name << ";" <<  getProgrammer(i).Gender << ";" <<  getProgrammer(i).BirthYear << ";" <<  getProgrammer(i).DeadYear << ";" << endl;
    }
    output.close();
}
void Programmers::read() {
    Programmer p;
    cout << "Name     : " ;
    cin >> p.Name;

    cout << "Gender   : " ;
    cin >> p.Gender;

    cout << "BirthYear : " ;
    cin >> p.BirthYear;

    cout << "Dead     : " ;
    cin >> p.DeadYear;

    add(p);
}

void Programmers::add(Programmer p) {
    programmers.push_back(p);
}

void Programmers::del(int nr) {
    programmers.erase(programmers.begin()+(nr-1));
}
Programmer Programmers::getProgrammer(int nr) {
    return programmers[nr];
}
int Programmers::size(){
    return programmers.size();
}

vector<Programmer> Programmers::Find(string sSearch) {
    vector<Programmer> pr;
    for (int i=0; i<programmers.size();i++) {
        if (programmers[i].Name.find(sSearch) != string::npos ||  // string::npos ef sSearch finnst ekki
            getProgrammer(i).Gender == sSearch ||
            getProgrammer(i).BirthYear == sSearch || getProgrammer(i).DeadYear == sSearch)
            pr.push_back(getProgrammer(i));
    }
    return pr;
}

void Programmers::Display(string sSearch) {
    for (int i=0; i<programmers.size();i++) {
        if (programmers[i].Name.find(sSearch) != string::npos || // string::npos ef sSearch finnst ekki
            getProgrammer(i).Gender == sSearch ||
            getProgrammer(i).BirthYear == sSearch || getProgrammer(i).DeadYear == sSearch) {
            cout << getProgrammer(i).Name << " - " << getProgrammer(i).Gender << " - " << getProgrammer(i).BirthYear << " - " << getProgrammer(i).DeadYear << endl;
        }
    }
}

void Programmers::sortListByName(){
    sort(programmers.begin(), programmers.end(), compare_name);
}
void Programmers::sortListByGender(){
    sortListByName();
    sort(programmers.begin(), programmers.end(), compare_gender);
}

