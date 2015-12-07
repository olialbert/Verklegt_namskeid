#ifndef PPINTERFACE_H
#define PPINTERFACE_H
#include "pcservice.h"
using namespace std;

class ppInterface
{
    public:
        ppInterface();
        int start();

    private:

        void sortProgrammers();

          // ask user for search string and displayes all programmers that are in the search criteria
        void search();

          // input : sSearch - search criteria
          // displayes all programmers that are in the search criteria
        void displayProgrammers(string sSearch);

          // reads info about the new programmer that the user puts inn and adds to the list
        void addProgrammer();

          // asks for nr of the programmer to delete and removes him from the list
        void deleteProgrammer();

          // input  : type=1 sorts by name
          //          type=2 sorts by gender
          //          else sorts by name
          // sorts the programmer list in given order
        void sortProgrammers(int type);

    private:
};

#endif // PPINTERFACE_H
