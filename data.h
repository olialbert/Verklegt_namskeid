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
        Programmer getProgrammer(int programmerId);

            // ToDo add comment ...
        vector<Programmer> findProgrammers(string search);

            //
        vector<Programmer> getProgrammers(int computerId);

            // input : p - programmer to be added
            // programmer p as been added to the programmers table
        void addProgrammer(Programmer p);

            // input : programmerId - Id of the programmer to be deleted
            // programmer with Id, programerId has been deleted from the programmers table
        void delProgrammer(int programmerId);

            //
        void updateProgrammer(int programmerId);

             // input : order - sort order
            // sets the display order for the selected programmers
        void orderProgrammersBy(string order);

        // ********* COMPUTERS *************************************************************************

            //
        Computer getComputer(int id);

            //
        vector<Computer> findComputer(string search);

            //
        vector<Computer> getComputers(int programmerID);

            // input : c - computer to be added
            // computer c as been added to the computers table
        void addComputer(Computer p);

            // input : computerId - Id of the computer to be deleted
            // computer with Id, computerId has been deleted from the computers table
        void delComputer(int computerId);

            // input : order - sort order
            // sets the display order for the selected computers
        void orderComputersBy(string order);

    private:
        QSqlDatabase mydb;
        string programmersOrderBy;
        string computersOrderBy;
        void loadDB(string sort);
};

#endif
