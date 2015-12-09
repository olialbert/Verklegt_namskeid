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
            // ask user for search string and displayes all computers that are in the search criteria
        void searchComputers();


            // input : sSearch - search criteria
            // displayes all programmers that are in the search criteria
        void displayProgrammers(string search);
            // input : sSearch - search criteria
            // displayes all computers that are in the search criteria
        void displayComputers(string search);

            // asks user for programmer ID and displayes info about the programmer and all computers connected to him
        void displayProgrammerAndComputers();

            // asks user for computer ID and displayes info about the computer and all programmers connected to it
        void displayComputerAndProgrammers();

            // reads info about the new programmer that the user puts inn and adds to the database
        void addProgrammer();

            // reads info about the new computer that the user puts inn and adds to the database
        void addComputer();

            // fetches selected programmer and user can change his info
        void updateProgrammer();

            // fetches selected computer and user can chage its info
        void updateComputer();

            // asks for ID of the programmer to delete and removes him from the database
        void deleteProgrammer();

            // asks for ID of the computer to delete and removes it from the database
        void deleteComputer();

          //adding connection from the programmer to computer
        void connectProgrammerToComputer();

          // displaying all the connections
        void displayAllConnections();

        pcService pcservice;
};

#endif // PPINTERFACE_H
