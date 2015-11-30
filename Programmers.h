#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H
#include <iostream>
#include <vector>
using namespace std;

struct Programmer {
    string Name;
    string Gender;
    string Birthday;
    string Deadday;
};

class Programmers
{
    public:
        Programmers();
        Programmer read();
        void add(Programmer p);
        void findAll(string sSearch);


    private:
        vector<Programmer> programmers;
        void load();
        void save();
};

#endif
