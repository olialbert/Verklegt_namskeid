#ifndef LISTI_H
#define LISTI_H
#include <iostream>
using namespace std;

class List
{
    public:
        List(string name, string gender, int birthday, int age);
        void getname();
        
    private:
		string name;
		string gender;
		int birthdate;
		int age;
};

#endif