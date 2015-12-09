#include "utilities/utils.h"
#include <sstream>
#include <cstdlib>

using namespace std;

namespace utils {


    char stringToGender(string str){
        if(stringToLower(str.substr(0, 1))== "f"){
            return 'f';
        }else{
            return 'm';
        }
    }

    string genderToString(char c){
        if(c == 'f'){
            return "Female";
        }else{
            return "Male";
        }
    }

    int yesNoToInt(string yesNo){
        if(stringToLower(yesNo.substr(0, 1))== "y"){
            return 1;
        }else{
            return 0;
        }
    }

    string intToYesNo(int i){
        if(i == 1){
            return "Yes";
        }else{
            return "No";
        }
    }

    string YearOfDeathToString(int year) {
        if (year==0)
            return "Alive";
        else
            return intToString(year);
    }

    // ***** following function where "borrowed" from week1 solution *****
    int stringToInt(string str){
        return atoi(str.c_str());
    }

    string stringToLower(string str){
        string result = "";

        for (unsigned int i = 0; i < str.length(); i++){
            char currentCharacter = str[i];
            // http://www.asciitable.com/
            if (currentCharacter <= 90 && currentCharacter >= 65){
                result += currentCharacter + 32;
            }
            else{
                result += currentCharacter;
            }
        }
        return result;
    }

    string intToString(int number){
        stringstream stream;
        stream << number;
        return stream.str();
    }
    // *******************************************************************

}

