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

        void proANDcomMenu();

          // ask user for search string and displayes all programmers that are in the search criteria
        void searchProgrammers();
        void searchComputers();


          // input : sSearch - search criteria
          // displayes all programmers that are in the search criteria
        void displayProgrammers(string search);
        void displayComputers(string search);
        void displayProgrammerAndComputers();

          // reads info about the new programmer that the user puts inn and adds to the list
        void addProgrammer();
        void addComputer();

          // asks for nr of the programmer to delete and removes him from the list
        void deleteProgrammer();
        void deleteComputer();

        void connectProgrammerToComputer();


        pcService pcservice;
};

#endif // PPINTERFACE_H
