#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H
#include <iostream>
#include <vector>
using namespace std;

struct Programmer {
    string Name;
    string Gender;
    string BirthYear;
    string DeadYear;
};

class Programmers
{
    public:
        Programmers();
        void read();
        void add(Programmer p);
        void del(int nr);
        Programmer getProgrammer(int nr);
        int size();
        int Find(string sSearch);
        void Display(string sSearch);
        void sortListByName();
        void sortListByGender();

        void save();
    private:
        vector<Programmer> programmers;
        void load();
        //bool compare_name (Programmer first, Programmer second);

};

#endif
