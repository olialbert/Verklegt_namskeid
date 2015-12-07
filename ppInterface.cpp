#include "ppInterface.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include "pcservice.h"
#include <stdio.h>
#include <string>

using namespace utils;
using namespace std;
using namespace constants;


ppInterface::ppInterface()
{

}

int ppInterface::start() {
    char choose;  // breyta fyrir val á aðgerð

    cout << "This is a program that contains information about famous computer scientists" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose one of the following actions" << endl;

    string s;
    do{
        cout << endl;
        cout << "1. Display Programmers " << endl;
        cout << "2. Search for programmers" << endl;
        cout << "3. Add programmer" << endl;
        cout << "4. Remove programmer" << endl;
        cout << "5. Sort programmers" << endl;
        cout << "9. Quit" << endl;
        cout << endl;
        cout << "Choose action : ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':
            displayProgrammers("");
            break;
        case '2':
            searchProgrammers();
            break;
        case '3':
            addProgrammer();
            break;
        case '4':
           deleteProgrammer();
            break;
        case '5':
            sortProgrammers();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '9');

    return 0;
}

void ppInterface::sortProgrammers() {
    char choose;  // breyta fyrir val á aðgerð

    string s;
    do{
        cout << endl;
        cout << "Sort by :" << endl;
        cout << "1. Name" << endl;
        cout << "2. Name desc" << endl;
        cout << "3. Gender" << endl;
        cout << "4. Gender desc" << endl;
        cout << endl;
        cout << "Choose Programmers sorting : ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_NAME);
            break;
        case '2':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_NAME_DESC);
            break;
        case '3':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER);
            break;
        case '4':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER_DESC);
            break;
        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4');
}

void ppInterface::searchProgrammers() {
    string sSearch;
    cout << "Search for : ";
    cin >> sSearch;
    displayProgrammers(sSearch);
}

string fmt(string s, int len) {
    return (s + "                        ").substr(0,len);
}
void ppInterface::displayProgrammers(string search) {
    vector<Programmer> programmers = pcservice.findProgrammers(search);
     for (unsigned int i = 0; i<programmers.size();  i++) {
            printf("%-4i : %-40s - %-8s - %-4i - %-4s\n",
                   programmers[i].programmerID,
                   programmers[i].Name.c_str(),
                   genderToString(programmers[i].Gender).c_str(),
                   programmers[i].BirthYear,
                   intToString(programmers[i].DeadYear).c_str());
    }
}

void ppInterface::addProgrammer() {

    Programmer p;

    cout << "Name     : " ;
    getline(cin, p.Name);

    string g;
    cout << "Gender   : " ;
    getline(cin, g);
    p.Gender = stringToGender(g);

    cout << "BirthYear : " ;
    string b;
    getline(cin, b);
    p.BirthYear = stringToInt(b);

    cout << "Dead     : " ;
    string d;
    getline(cin, d);
    p.DeadYear = stringToInt(d);

    pcservice.addProgrammer(p);
}

void ppInterface::deleteProgrammer(){
    int programmerID;
    cout << "Delete programmer with ID: ";
    cin >> programmerID;
    pcservice.deleteProgrammer(programmerID);
}

