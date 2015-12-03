#include "data.h"
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


Data::Data() {
    load();
}

Programmer Data::get(int nr) {
    return programmers[nr];
}

int Data::size(){
    return programmers.size();
}

void Data::add(Programmer p) {
    programmers.push_back(p);
}

void Data::del(int nr) {
    programmers.erase(programmers.begin()+(nr-1));
}


void Data::sortByName(){
    sort(programmers.begin(), programmers.end(), compare_name);
}

void Data::sortByGender(){
    sortByName();
    sort(programmers.begin(), programmers.end(), compare_gender);
}

void Data::save() {        // saves all programmers to file
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


void Data::load() {             // loads all programmers from text file
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
