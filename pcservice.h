#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H
#include <iostream>
#include <vector>
#include "programmer.h"
#include "computer.h"
#include "data.h"
using namespace std;


class pcService
{
    public:
        pcService();

// ********* PROGRAMMERS *************************************************************************

            // input : programmerId - id of the programmer
            // returns : programmerinfo  for programmer with id programmerId
        Programmer getProgrammer(int programmerId);

            // input : searc string
            // returns : vector of programmers that are in the search criteria
        vector<Programmer> findProgrammers(string search);

            // input : computerID - id of the computer
            // returns : vector of programmers thar are connected to computer with id computerID
        vector<Programmer> getProgrammers(int computerId);

            // input : p - programmer to be added
            // programmer p as been added to the programmers table
        void addProgrammer(Programmer p);

            // input : programmerId - Id of the programmer to be deleted
            // programmer with Id, programerId has been deleted from the programmers table
        void deleteProgrammer(int programmerId);

             // input : p - programmer info to be updated
            // all info about programmer p has been updated
        void updateProgrammer(Programmer p);

            // input : order - sort order
            // sets the display order for the selected programmers
        void orderProgrammersBy(string order);

            // input : programmerId and computerID
            // programmer and computer are connected
        void connectProgrammerToComputer(int computerID, int programmerID);

// ********* COMPUTERS *************************************************************************

            // input : computerID - id of the computer
            // returns : computerinfo c for computer with id computerId
        Computer getComputer(int computerID);

            // input : searc string
            // returns : vector of computers that are in the search criteria
        vector<Computer> findComputers(string search);

            // input : programmerID - id of the programmer
            // returns : vector of computers thar are connected to programmer with id programmerID
        vector<Computer> getComputers(int programmerID);

            // input : c - computer to be added
            // computer c as been added to the computers table
        void addComputer(Computer c);

            // input : computerId - Id of the computer to be deleted
            // computer with Id, computerId has been deleted from the computers table
        void deleteComputer(int computerId);

            // input : computerinfo c to be updated
            // all info about computer c has been updated
        void updateComputer(Computer c);

            // input : order - sort order
            // sets the display order for the selected computers
        void orderComputersBy(string order);


    private:
        Data data;
};

#endif
