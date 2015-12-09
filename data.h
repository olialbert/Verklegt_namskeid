#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <QtSql/QSqlDatabase>
#include "Programmer.h"
#include "computer.h"

using namespace std;


class Data
{
    public:
        Data();
        ~Data();

// ********* PROGRAMMERS *************************************************************************

           // input : programmerId - id of the programmer
           // returns : programmer with id programmerId
        Programmer getProgrammer(int programmerID);

           // input : sets programmersID to vektor
           // returns : programmersID from database to vector
        vector<Programmer> findProgrammers(string search);

            //
        vector<Programmer> getProgrammers(int computerID);

           // input : p - programmer to be added
           // programmer p as been added to the programmers table
        void addProgrammer(Programmer p);

           // input : programmerId - Id of the programmer to be deleted
           // programmer with Id, programerId has been deleted from the programmers table
        void deleteProgrammer(int programmerID);

            // input : programmer to be updated
            // all info about programmer p has been updated
        void updateProgrammer(Programmer p);

           // input : order - sort order
           // sets the display order for the selected programmers
        void orderProgrammersBy(string order);

           // input : computerID and programmerID
           // returns : the connection between the programmer and the computer
        void connectProgrammerToComputer(int computerID, int programmerID);

// ********* COMPUTERS *************************************************************************

           // input : computerId - id of the computer
           // returns : computer with id computerId
        Computer getComputer(int computerID);

           // input : sets computersID to vektor
           // returns : computersID information from database to vector
        vector<Computer> findComputers(string search);

           // input : gets computersID to vektor
           // returns :  gets the connection between programmers and computers
        vector<Computer> getComputers(int programmerID);

           // input : c - computer to be added
           // computer c as been added to the computers table
        void addComputer(Computer c);

           // input : computerId - Id of the computer to be deleted
           // computer with Id, computerId has been deleted from the computers table
        void deleteComputer(int computerID);

            // input : computer to be updated
            // all info about computer c has been updated
        void updateComputer(Computer c);

           // input : order - sort order
           // sets the display order for the selected computers
        void orderComputersBy(string order);

    private:
        QSqlDatabase mydb;
        string programmersOrderBy;
        string computersOrderBy;
};

#endif
