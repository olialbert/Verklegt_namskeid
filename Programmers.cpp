#include "Programmers.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

bool compare_name (Programmer first, Programmer second) // takes first programmer and compares it with the second programmber based on their name.
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
bool compare_gender(Programmer first, Programmer second) // takes first programmer and compares it with the second programmber based on their gender.
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

Programmer Programmers::getProgrammer(int nr) {
    return programmers[nr];
}

int Programmers::size(){
    return programmers.size();
}

void Programmers::add(Programmer p) {
    programmers.push_back(p);
}

void Programmers::del(int nr) {
    programmers.erase(programmers.begin()+(nr-1));
}

void Programmers::Find(vector<int>& pr, string sSearch) {
    pr.clear();
    for (unsigned int i=0; i<programmers.size();i++) {
        if (programmers[i].Name.find(sSearch) != string::npos ||  // string::npos if it does not find sSearch
            getProgrammer(i).Gender == sSearch ||
            getProgrammer(i).BirthYear == sSearch || getProgrammer(i).DeadYear == sSearch)
            pr.push_back(i);
    }
}

void Programmers::sortByName(){
    sort(programmers.begin(), programmers.end(), compare_name);
}

void Programmers::sortByGender(){
    sortByName();
    sort(programmers.begin(), programmers.end(), compare_gender);
}

void Programmers::save() {        // saves all programmers to file
   ofstream output;
   output.open("Programmers.txt");
     if(output.fail()){
        cout << "error" << endl;
        return;
    }
    for (int i=0; i<size();i++) {
        output << getProgrammer(i).Name << ";" <<  getProgrammer(i).Gender << ";" <<  getProgrammer(i).BirthYear << ";" <<  getProgrammer(i).DeadYear << ";" << endl;
    }
    output.close();
}


void Programmers::load() {             // loads all programmers from text file
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
