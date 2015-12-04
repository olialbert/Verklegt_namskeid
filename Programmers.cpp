#include "Programmers.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace utils;

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
        if (stringToLower(data.get(i).Name).find(stringToLower(sSearch)) != string::npos ||
            data.get(i).Gender == sSearch[0] ||
            data.get(i).BirthYear == stringToInt(sSearch) || data.get(i).DeadYear == stringToInt(sSearch))
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
