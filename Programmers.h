#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H
#include <iostream>
#include <vector>
#include "Programmer.h"

using namespace std;


class Programmers
{
    public:
        Programmers();

          // input : nr - nr of the programmer
          // returns : programmer at position nr
        Programmer getProgrammer(int nr);

          // returns : count of programmers
        int size();

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
        void sortByName();

          // sorts the programmers by gender+name
        void sortByGender();

          // saves the programmers to disk
        void save();
    private:
        vector<Programmer> programmers;
        void load();
};

#endif
