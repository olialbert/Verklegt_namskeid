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

/*void pcService::updateProgrammer(int programmerId){
     data.updateProgrammer(programmerId);
}*/

void pcService::orderProgrammersBy(string order){
    data.orderProgrammersBy(order);
}

// ********* COMPUTERS *************************************************************************

    //
Computer pcService::getComputer(int id){
    return data.getComputer(id);
}

    //
vector<Computer> pcService::findComputer(string search){
    return data.findComputer(search);
}

    //
vector<Computer> pcService::getComputers(int programmerID){
    return data.getComputers(programmerID);
}

    // input : c - computer to be added
    // computer c as been added to the computers table
void pcService::addComputer(Computer c){
    data.addComputer(c);
}

    // input : computerId - Id of the computer to be deleted
    // computer with Id, computerId has been deleted from the computers table
void pcService::deleteComputer(int computerId){
    data.deleteComputer(computerId);
}


    // input : order - sort order
    // sets the display order for the selected computers
void pcService::orderComputersBy(string order){
        data.orderComputersBy(order);
}





