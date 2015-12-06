#include "Programmers.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

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





