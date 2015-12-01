#ifndef PPINTERFACE_H
#define PPINTERFACE_H
#include "Programmers.h"
using namespace std;

class ppInterface
{
    public:
        ppInterface();
        void search();
        void display(string sSearch);
        void addProgrammer();
        void save();
        void deleteProgrammer();
        void sortProgrammers(int type);
    private:
        Programmers programmers;
};

#endif // PPINTERFACE_H
