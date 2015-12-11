#include "pcservice.h"
#include "utilities/utils.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace utils;

pcService::pcService() {

}

// ********* PROGRAMMERS *************************************************************************


Programmer pcService::getProgrammer(int programmerId){
    return data.getProgrammer(programmerId);
}

vector<Programmer> pcService::findProgrammers(string search) {
    return data.findProgrammers(search);
}

vector<Programmer> pcService::getProgrammers(int computerId){
    return data.getProgrammers(computerId);
}


void pcService::addProgrammer(Programmer p){
     data.addProgrammer(p);
}

void pcService::deleteProgrammer(int programmerId){
     data.deleteProgrammer(programmerId);
}

void pcService::updateProgrammer(Programmer p){
     data.updateProgrammer(p);
}

void pcService::orderProgrammersBy(string order){
    data.orderProgrammersBy(order);
}

void pcService::connectProgrammerToComputer(int computerID, int programmerID){
    data.connectProgrammerToComputer(computerID, programmerID);
}

// ********* COMPUTERS *************************************************************************


Computer pcService::getComputer(int computerID){
    return data.getComputer(computerID);
}


vector<Computer> pcService::findComputers(string search){
    return data.findComputers(search);
}

vector<Computer> pcService::getComputers(int programmerID){
    return data.getComputers(programmerID);
}

void pcService::addComputer(Computer c){
    data.addComputer(c);
}

void pcService::deleteComputer(int computerId){
    data.deleteComputer(computerId);
}

void pcService::updateComputer(Computer c){
    data.updateComputer(c);
}

void pcService::orderComputersBy(string order){
        data.orderComputersBy(order);
}



