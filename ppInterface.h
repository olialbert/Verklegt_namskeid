#ifndef PPINTERFACE_H
#define PPINTERFACE_H
#include "Programmers.h"
using namespace std;

class ppInterface
{
    public:
        ppInterface();
        virtual ~ppInterface();
        void search();
        void display(string sSearch);
        void readProgrammer();
        void save();
        void deleteProgrammer();
        void sortProgrammers(int type);
    protected:
    private:
        Programmers programmers;
};

#endif // PPINTERFACE_H
