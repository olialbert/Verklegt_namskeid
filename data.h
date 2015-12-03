#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include "Programmer.h"

using namespace std;


class Data
{
    public:
        Data();

          // input : nr - nr of the programmer
          // returns : programmer at position nr
        Programmer get(int nr);

          // returns : count of programmers
        int size();

          // input : p - programmer to be added
          // programmer p as been added to the programmers list
        void add(Programmer p);

          // programmer at nr has been deleted from the programmers list
        void del(int nr);

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
