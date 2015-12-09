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
            //Menu for Programmers
        void programmersMenu();
        void sortProgrammersMenu();

            //Menu for Computers
        void computersMenu();
        void sortComputersMenu();

            // Menu for programmers and computers
        void proAndComMenu();

          // ask user for search string and displayes all programmers that are in the search criteria
        void searchProgrammers();
        void searchComputers();


          // input : sSearch - search criteria
          // displayes all programmers that are in the search criteria
        void displayProgrammers(string search);
        void displayComputers(string search);
        void displayProgrammerAndComputers();
        void displayComputerAndProgrammers();

          // reads info about the new programmer that the user puts inn and adds to the list
        void addProgrammer();
        void addComputer();

        void updateProgrammer();
        void updateComputer();

          // asks for nr of the programmer to delete and removes him from the list
        void deleteProgrammer();
        void deleteComputer();

          //adding connection from the programmer to computer
        void connectProgrammerToComputer();
        void displayAll();

          // displaying all the connections
        void displayAllConnections();

        pcService pcservice;
};

#endif // PPINTERFACE_H
