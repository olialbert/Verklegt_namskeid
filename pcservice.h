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
            // returns : programmer with id programmerId
        Programmer getProgrammer(int programmerId);

            //
        vector<Programmer> findProgrammers(string search);

            //
        vector<Programmer> getProgrammers(int computerId);

            // input : p - programmer to be added
            // programmer p as been added to the programmers table
        void addProgrammer(Programmer p);

            // input : programmerId - Id of the programmer to be deleted
            // programmer with Id, programerId has been deleted from the programmers table
        void deleteProgrammer(int programmerId);
        void updateProgrammer(int programmerId);

             // input : order - sort order
            // sets the display order for the selected programmers
        void orderProgrammersBy(string order);

        void connectProgrammerToComputer(int computerID, int programmerID);

        // ********* COMPUTERS *************************************************************************

            //
        Computer getComputer(int id);

            //
        vector<Computer> findComputers(string search);

            //
        vector<Computer> getComputers(int programmerID);

            // input : c - computer to be added
            // computer c as been added to the computers table
        void addComputer(Computer c);

            // input : computerId - Id of the computer to be deleted
            // computer with Id, computerId has been deleted from the computers table
        void deleteComputer(int computerId);

            // input : order - sort order
            // sets the display order for the selected computers
        void orderComputersBy(string order);

    private:
        Data data;
};

#endif
