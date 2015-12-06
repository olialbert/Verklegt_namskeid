#include "Programmers.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

<<<<<<< Updated upstream
using namespace utils;

Programmers::Programmers() {

}
vector<Programmer> findProgrammers(string search){
     return data.finProgrammers(search);
}

Programmer getProgrammer(int programmerId){
    return data.getProgrammer(programmerId);
}

vector<Programmer> getProgrammers(int computerId){
    return data.getProgrammers(computerId);
}

void addProgrammer(Programmer p){
    return data.addProgrammer(p);
}

void delProgrammer(int programmerId){
    return data.delProgrammer(programmerId);
}
void updateProgrammer(int programmerId){
    return data.updateProgrammer(programmerId);
}

void orderProgrammersBy(string order){
    return data.orderProgrammersBy(order);
}





/*
Programmer Programmers::getProgrammer(int nr) {
    return data.get(nr);
}

int Programmers::size(){
    return data.size();
}

void Programmers::add(Programmer p) {
    data.add(p);
}

void Programmers::del(int nr) {
    data.del(nr);
}

void Programmers::Find(vector<int>& pr, string sSearch) {
    pr.clear();
    for (int i=0; i<data.size();i++) {
        if (stringToLower(data.get(i).Name).find(stringToLower(sSearch)) != string::npos ||
            data.get(i).Gender == sSearch[0] ||
            data.get(i).BirthYear == stringToInt(sSearch) ||
            data.get(i).DeadYear == stringToInt(sSearch))
            pr.push_back(i);
    }
}

void Programmers::sortByName(){
    data.sortByName();
}

void Programmers::sortByGender(){
    data.sortByName();
    data.sortByGender();
}

void Programmers::save() {
    data.save();
}
*/
=======

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
>>>>>>> Stashed changes
