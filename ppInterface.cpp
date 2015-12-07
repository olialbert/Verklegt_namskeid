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

int ppInterface::mainMenu(){
    char choise;
    string s;

    do{
        cout << endl;
        cout << "*******  MAIN MENU  *********************** " << endl;
        cout << "Please choose one of the fallowing actions: " << endl;
        cout << endl;
        cout << "1. PROGRAMMERS   " << endl;
        cout << "2. COMPUTERS     " << endl;
        cout << "9. QUIT          " << endl;
        cout << endl;
        cout << "Action number:   ";
        cin >> choise;
        getline(cin, s);
        cout << endl;


        switch (choise){
        case '1':
            programmersMenu();
            break;
        case '2':
            computersMenu();
            break;
        default:
            if(choise != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choise != '9');
    return 0;
}


void ppInterface::programmersMenu() {
    char choose;
    string s;



    do{
        cout << endl;
        cout << "*******  PROGRAMMERS MENU  **************** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << endl;
        cout << "1. Display          " << endl;
        cout << "2. Search           " << endl;
        cout << "3. Add              " << endl;
        cout << "4. Remove           " << endl;
        cout << "5. Display order    " << endl;
        cout << "9. Back to Main Menu" << endl;
        cout << endl;
        cout << "Action number: ";
        cin >> choose;
        getline(cin, s);
        cout << endl;

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
            sortProgrammersMenu();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '9');
}

void ppInterface::sortProgrammersMenu() {
    char choose;  // breyta fyrir val á aðgerð
    string s;

    do{
        cout << endl;
        cout << "*******  PROGRAMMERS DISPLAY MENU  ******** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << "Order programmers by :" << endl;
        cout << endl;
        cout << "1. Name ascending order" << endl;
        cout << "2. Name descending order" << endl;
        cout << "3. Gender ascending order" << endl;
        cout << "4. Gender descending order" << endl;
        cout << "5. Birthyear ascending order " << endl;
        cout << "6. Birthyear descending order " << endl;
        cout << "7. Year of death ascending order " << endl;
        cout << "8. Year of death descending order " << endl;
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
        case '5':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR);
            break;
        case '6':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR_DESC);
            break;
        case '7':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR);
            break;
        case '8':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR_DESC);
            break;
        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6' && choose != '7' && choose != '8');
}

void ppInterface::computersMenu(){
    char choose;
    string s;

    do{
        cout << endl;
        cout << "*******  COMPUTERS MENU  ****************** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << endl;
        cout << "1. Display           " << endl;
        cout << "2. Search            " << endl;
        cout << "3. Add               " << endl;
        cout << "4. Delete            " << endl;
        cout << "5. Display order     " << endl;
        cout << "9. Back to Main Menu " << endl;
        cout << endl;
        cout << "Action number: ";
        cin >> choose;
        getline(cin, s);
        cout << endl;

        switch (choose){
        case '1':
            displayComputers("");
            break;
        case '2':
            searchComputers();
            break;
        case '3':
            addProgrammer();
            break;
        case '4':
           deleteProgrammer();
            break;
        case '5':
            sortProgrammersMenu();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '9');

}

void ppInterface::sortComputersMenu(){
    char choose;  // breyta fyrir val á aðgerð
    string s;

    do{
        cout << endl;
        cout << "*******  COMPUTERS DISPLAY MENU  ********** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << "Order computers by :" << endl;
        cout << endl;
        cout << "1. Name ascending order" << endl;
        cout << "2. Name descending order" << endl;
        cout << "3. Gender ascending order" << endl;
        cout << "4. Gender descending order" << endl;
        cout << "5. Birthyear ascending order " << endl;
        cout << "6. Birthyear descending order " << endl;
        cout << "7. Year of death ascending order " << endl;
        cout << "8. Year of death descending order " << endl;
        cout << endl;
        cout << "Choose computers display order: ";
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
        case '5':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR);
            break;
        case '6':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR_DESC);
            break;
        case '7':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR);
            break;
        case '8':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR_DESC);
            break;

        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6' && choose != '7' && choose != '8');
}

void ppInterface::searchProgrammers() {
    string search;
    cout << "Search for : ";
    cin >> search;
    displayProgrammers(search);
}

void ppInterface::searchComputers(){
    string search;
    cout << "Search for : ";
    cin >> search;
    displayComputers(search);
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

void ppInterface::displayComputers(string search) {
    vector<Computer> computers = pcservice.findComputers(search);
     for (unsigned int i = 0; i<computers.size();  i++) {
            printf("%-4i : %-40s - %-45s - %-4s - %-4s\n",
                   computers[i].computerID,
                   computers[i].Name.c_str(),
                   computers[i].Type.c_str(),
                   intToYesNo(computers[i].WasItBuilt).c_str(),
                   intToString(computers[i].YearBuilt).c_str());
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

    cout << "Year of Death     : " ;
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

