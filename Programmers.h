#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H
#include <iostream>
#include <vector>
#include "Programmer.h"
#include "data.h"
using namespace std;


class Programmers
{
    public:
        Programmers();

          // input : nr - nr of the programmer
          // returns : programmer at position nr
        Programmer getProgrammer(int nr);

          // input : p - programmer to be added
          // programmer p as been added to the programmers list
        void add(Programmer p);

          // programmer at nr has been deleted from the programmers list
        void del(int nr);

          // input : v - vector<int>
          //         sSearch - search criteria
          // v includes nr of all programmers that fullfill the search criteria
        void Find(vector<int>& pr, string sSearch);

          // sorts the programmers by name

        // returns the numbers of all programmers that matches the search criteria
        void read();
        void add(Programmer p);
        void del(int nr);

        // returns the numbers of all programmers that matches the search criteria
        void Find(vector<int>& pr, string sSearch);
    private:
        Data data;
};

#endif
