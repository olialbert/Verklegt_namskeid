#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


// This file contains reusable utility functions used throughout the application


namespace utils {    


    char stringToGender(string str);
    string genderToString(char c);

    int yesNoToInt(string yesNo);
    string intToYesNo(int i);

    string YearOfDeathToString(int year);

    // ***** following function where "borrowed" from week1 solution *****
    int stringToInt(string str);
    string stringToLower(string str);
    string intToString(int number);
    // *******************************************************************
}

#endif // UTILS_H

