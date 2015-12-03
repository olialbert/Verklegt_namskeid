#include "Programmers.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>


Programmers::Programmers() {

}

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
        if (data.get(i).Name.find(sSearch) != string::npos ||  // string::npos if it does not find sSearch
            data.get(i).Gender == sSearch ||
            ""+data.get(i).BirthYear == sSearch || ""+data.get(i).DeadYear == sSearch)
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

void Programmers::save() {        // saves all programmers to file
    data.save();
}
