#ifndef PPINTERFACE_H
#define PPINTERFACE_H
#include "Programmers.h"
using namespace std;

class ppInterface
{
    public:
        ppInterface();
<<<<<<< Updated upstream

        int start();

    private:

          // ask user for search string and displayes all programmers that are in the search criteria
=======
>>>>>>> Stashed changes
        void search();

          // input : sSearch - search criteria
          // displayes all programmers that are in the search criteria
        void display(string sSearch);
<<<<<<< Updated upstream

          // reads info about the new programmer that the user puts inn and adds to the list
        void addProgrammer();

          // saves all programmers to disk
=======
        void addProgrammer();
>>>>>>> Stashed changes
        void save();

          // asks for nr of the programmer to delete and removes him from the list
        void deleteProgrammer();

          // input  : type=1 sorts by name
          //          type=2 sorts by gender
          //          else sorts by name
          // sorts the programmer list in given order
        void sortProgrammers(int type);
<<<<<<< Updated upstream

=======
    private:
>>>>>>> Stashed changes
        Programmers programmers;
};

#endif // PPINTERFACE_H
