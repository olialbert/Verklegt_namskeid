#ifndef PPINTERFACE_H
#define PPINTERFACE_H
#include "pcservice.h"

using namespace std;

class ppInterface
{
    public:
        ppInterface();

        int mainMenu();

    private:
            //Programmers Menues
        void programmersMenu();
        void sortProgrammersMenu();

        void computersMenu();
        void sortComputersMenu();

          // ask user for search string and displayes all programmers that are in the search criteria
        void searchProgrammers();

          // input : sSearch - search criteria
          // displayes all programmers that are in the search criteria
        void displayProgrammers(string search);

          // reads info about the new programmer that the user puts inn and adds to the list
        void addProgrammer();

          // asks for nr of the programmer to delete and removes him from the list
        void deleteProgrammer();

    private:
        pcService pcservice;
};

#endif // PPINTERFACE_H
