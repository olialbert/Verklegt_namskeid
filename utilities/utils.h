#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {    
    vector<string> splitString(string line, char delimeter);

    int stringToInt(string str);

    string stringToLower(string str); //stolen

    string intToString(int number);

    char stringToGender(string str);

    string genderToString(char c);
}

#endif // UTILS_H

