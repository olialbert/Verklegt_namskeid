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
        Programmer getProgrammer(int nr);
        int size();
        void read();
        void add(Programmer p);
        void del(int nr);

        // returns the numbers of all programmers that matches the search criteria
        void Find(vector<int>& pr, string sSearch);
        void sortByName();
        void sortByGender();
        void save();
    private:
        vector<Programmer> programmers;
        void load();
};

#endif
