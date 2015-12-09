#include "ppInterface.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include "pcservice.h"
#include <stdio.h>
#include <string>

using namespace utils;
using namespace std;
using namespace constants;


ppInterface::ppInterface(){
}

int ppInterface::mainMenu(){
    char choise;
    string s;

    do{
        cout << endl;
        cout << "********************  MAIN MENU  ******************** " << endl;
        cout << "Please choose one of the fallowing actions: " << endl;
        cout << endl;
        cout << "1. Programmers             " << endl;
        cout << "2. Computers               " << endl;
        cout << "3. Programmers and Computer" << endl;
        cout << "9. Quit                    " << endl;
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
        case '3':
            proAndComMenu();
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
        cout << "***************  PROGRAMMERS MENU  ****************** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << endl;
        cout << "1. Display             " << endl;
        cout << "2. Display order       " << endl;
        cout << "3. Add                 " << endl;
        cout << "4. Edit                " << endl;
        cout << "5. Remove              " << endl;
        cout << "6. Search              " << endl;
        cout << "9. Back to Main Menu   " << endl;
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
            sortProgrammersMenu();
            break;
        case '3':
            addProgrammer();
            break;
        case '4':
            updateProgrammer();
            break;
        case '5':
            displayProgrammers("");
            deleteProgrammer();
            break;
        case '6':
            searchProgrammers();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '9');
}

void ppInterface::sortProgrammersMenu() {
    char choose;
    string s;

    do{
        cout << endl;
        cout << "**************  PROGRAMMERS DISPLAY MENU  *********** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << "Order programmers by :            " << endl;
        cout << endl;
        cout << "1. Name ascending order           " << endl;
        cout << "2. Name descending order          " << endl;
        cout << "3. Gender ascending order         " << endl;
        cout << "4. Gender descending order        " << endl;
        cout << "5. Birthyear ascending order      " << endl;
        cout << "6. Birthyear descending order     " << endl;
        cout << "7. Year of death ascending order  " << endl;
        cout << "8. Year of death descending order " << endl;
        cout << endl;
        cout << "Choose Programmers sorting :      ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_NAME);
            displayProgrammers("");
            break;
        case '2':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_NAME_DESC);
            displayProgrammers("");
            break;
        case '3':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER);
            displayProgrammers("");
            break;
        case '4':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER_DESC);
            displayProgrammers("");
            break;
        case '5':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR);
            displayProgrammers("");
            break;
        case '6':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_BIRTHYEAR_DESC);
            displayProgrammers("");
            break;
        case '7':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR);
            displayProgrammers("");
            break;
        case '8':
            pcservice.orderProgrammersBy(PROGRAMMERS_ORDER_DEADYEAR_DESC);
            displayProgrammers("");
            break;
        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6' && choose != '7' && choose != '8');
}

void ppInterface::computersMenu(){
    char choose;
    string s;

    do{
        cout << endl;
        cout << "**************  COMPUTERS MENU  ********************* " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << endl;
        cout << "1. Display           " << endl;
        cout << "2. Display order     " << endl;
        cout << "3. Add               " << endl;
        cout << "4. Edit              " << endl;
        cout << "5. Remove            " << endl;
        cout << "5. Search            " << endl;
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
            sortComputersMenu();
            break;
        case '3':
            addComputer();
            break;
        case '4':
            updateComputer();
            break;
        case '5':
           displayComputers("");
           deleteComputer();
            break;
        case '6':
            searchComputers();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '9');
}

void ppInterface::sortComputersMenu(){
    char choose;
    string s;

    do{
        cout << endl;
        cout << "*************  COMPUTERS DISPLAY MENU  ************** " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << "Order computers by :" << endl;
        cout << endl;
        cout << "1. Name ascending order          " << endl;
        cout << "2. Name descending order         " << endl;
        cout << "3. Type ascending order          " << endl;
        cout << "4. Type descending order         " << endl;
        cout << "5. Was it built ascending order  " << endl;
        cout << "6. Was it built descending order " << endl;
        cout << "7. Year built ascending order    " << endl;
        cout << "8. Year built descending order   " << endl;
        cout << endl;
        cout << "Choose computers display order: ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':
            pcservice.orderComputersBy(COMPUTERS_ORDER_NAME);
            displayComputers("");
            break;
        case '2':
            pcservice.orderComputersBy(COMPUTERS_ORDER_NAME_DESC);
            displayComputers("");
            break;
        case '3':
            pcservice.orderComputersBy(COMPUTERS_ORDER_TYPE);
            displayComputers("");
            break;
        case '4':
            pcservice.orderComputersBy(COMPUTERS_ORDER_TYPE_DESC);
            displayComputers("");
            break;
        case '5':
            pcservice.orderComputersBy(COMPUTERS_ORDER_WASITBUILT);
            displayComputers("");
            break;
        case '6':
            pcservice.orderComputersBy(COMPUTERS_ORDER_WASITBUILT_DESC);
            displayComputers("");
            break;
        case '7':
            pcservice.orderComputersBy(COMPUTERS_ORDER_YEARBUILT);
            displayComputers("");
            break;
        case '8':
            pcservice.orderComputersBy(COMPUTERS_ORDER_YEARBUILT_DESC);
            displayComputers("");
            break;
        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6' && choose != '7' && choose != '8');
}

void ppInterface::proAndComMenu() {
    char choose;
    string s;

    do{
        cout << endl;
        cout << "******  PROGRAMMERS AND COMPUTERS MENU  ************* " << endl;
        cout << "Please choose one of the following actions: " << endl;
        cout << endl;
        cout << "1. Find programmers connection to computer        " << endl;
        cout << "2. Find computers connection to programmer        " << endl;
        cout << "3. Connect Computers and Programmers              " << endl;
        cout << "4. display all connections                        " << endl;
        cout << "9. Back to Main Menu                              " << endl;
        cout << endl;
        cout << "Action number: ";
        cin >> choose;
        getline(cin, s);
        cout << endl;

        switch (choose){
        case '1':
            displayProgrammerAndComputers();
            break;
        case '2':
            displayComputerAndProgrammers();
            break;
        case '3':
            connectProgrammerToComputer();
            break;
        case '4':
            displayAllConnections();
            break;
        default:
            if(choose != '9')
                cout << "Invalid choice" << endl;
            break;
        }
       }while(choose != '9');
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
    printf("%-4s  %-40s  %-8s  %-4s  %-4s\n", "ID","Name","Gender","BirthYear","Year of Death");
    printf("------------------------------------------------------------------------------------------------------------------\n");
     for (unsigned int i = 0; i<programmers.size();  i++) {
            printf("%-4i  %-40s  %-8s  %-9i  %-4s\n",
                   programmers[i].programmerID,
                   programmers[i].Name.c_str(),
                   genderToString(programmers[i].Gender).c_str(),
                   programmers[i].BirthYear,
                   YearOfDeathToString(programmers[i].DeadYear).c_str());
    }
}

void ppInterface::displayComputers(string search) {
    vector<Computer> computers = pcservice.findComputers(search);
    printf("%-4s  %-40s  %-45s  %-4s  %-4s\n", "ID","Name","Type","Built","Year");
    printf("------------------------------------------------------------------------------------------------------------------\n");
     for (unsigned int i = 0; i<computers.size();  i++) {
            printf("%-4i  %-40s  %-45s  %-4s  %-4s\n",
                   computers[i].computerID,
                   computers[i].Name.c_str(),
                   computers[i].Type.c_str(),
                   intToYesNo(computers[i].WasItBuilt).c_str(),
                   intToString(computers[i].YearBuilt).c_str());
    }
}

void ppInterface::addProgrammer() {

    Programmer p;

    cout << "Name             : " ;
    getline(cin, p.Name);

    string g;
    cout << "Gender (M/F)     : " ;
    getline(cin, g);
    p.Gender = stringToGender(g);

    string b;
    cout << "BirthYear        : " ;
    getline(cin, b);
    if (stringToInt(b) <= 1500 ){
        cout << endl;
        cout << "Invalid BirthYear, programmer was not added !" << endl;
        return;
    }
    p.BirthYear = stringToInt(b);

    string d;
    cout << "Year of Death     : " ;
    getline(cin, d);
    p.DeadYear = stringToInt(d);

    pcservice.addProgrammer(p);
    cout << endl;
    cout << "Programmer has been succsessfully Added!" << endl;

}


void ppInterface::addComputer() {

    Computer c;

    cout << "Name                : " ;
    getline(cin, c.Name);

    cout << "Type                : " ;
    getline(cin, c.Type);


    cout << "Was it built (Y/N)? : " ;
    string wb;
    getline(cin, wb);
    c.WasItBuilt = yesNoToInt(wb);

    cout << "Year built          : " ;
    string yb;
    getline(cin, yb);
    c.YearBuilt = stringToInt(yb);
    if (c.YearBuilt <= 1500){
        cout << endl;
        cout << "Invalid year, computer was not added" << endl;
        return;
    }
        pcservice.addComputer(c);
        cout << endl;
        cout << "Computer has been succsessfully Added!" << endl;
}

void ppInterface::updateProgrammer() {
    string programmerID;
    cout << "Edit programmer with ID number : ";
    getline(cin, programmerID);

    Programmer p = pcservice.getProgrammer(stringToInt(programmerID));

    if(p.programmerID <= 0){
        cout << "Invalid programmer ID!" << endl;
        return;
    }

    string sInput;
    cout << "Name (" << p.Name << ") : ";
    getline(cin, sInput);
    if (sInput.length()>0) {
        p.Name = sInput;
    }

    cout << "Gender (" << genderToString(p.Gender) << ")  : " ;
    getline(cin, sInput);
    if (sInput.length()>0) {
        p.Gender = stringToGender(sInput);
    }

    cout << "BirthYear (" << intToString(p.BirthYear) << ") : " ;
    getline(cin, sInput);
    if (stringToInt(sInput) > 1500 ){
        p.BirthYear = stringToInt(sInput);
    }

    cout << "Year of Death (" << YearOfDeathToString(p.DeadYear) << ") : " ;
    getline(cin, sInput);
    if (stringToInt(sInput) > 1500 ){
        p.DeadYear = stringToInt(sInput);
    }
     pcservice.updateProgrammer(p);
}

void ppInterface::updateComputer() {
    string computerID;
    cout << "Edit programmer with ID number : ";
    getline(cin, computerID);

    Computer c = pcservice.getComputer(stringToInt(computerID));

    if(c.computerID <= 0){
        cout << "Invalid computer ID!" << endl;
        return;
    }

    string sInput;
    cout << "Name (" << c.Name << ") : " ;
    getline(cin, sInput);
    if (sInput.length()>0) {
        c.Name = sInput;
    }

    cout << "Type(" << c.Type << ") : " ;
    getline(cin, sInput);
    if (sInput.length()>0) {
        c.Type = sInput;
    }

    cout << "Was it built (" << intToYesNo(c.WasItBuilt) << ") : " ;
    getline(cin, sInput);
    if (sInput.length()>0) {
        c.WasItBuilt = yesNoToInt(sInput);
    }

    cout << "Year built (" << intToString(c.YearBuilt) << ") : " ;
    getline(cin, sInput);
    if (stringToInt(sInput) > 1500 ){
        c.YearBuilt = stringToInt(sInput);
    }

    pcservice.updateComputer(c);
}

void ppInterface::deleteProgrammer(){
    int programmerID;
    cout << "Delete programmer with ID: ";
    cin >> programmerID;
    pcservice.deleteProgrammer(programmerID);
    cout << endl;
    cout << "Programmer has been succsessfully removed!" << endl;
}

void ppInterface::deleteComputer(){
    int computerID;
    cout << "Delete computer with ID: ";
    cin >> computerID;
    pcservice.deleteComputer(computerID);
    cout << endl;
    cout << "Computer has been succsessfully removed!" << endl;
}

void ppInterface::connectProgrammerToComputer(){
    int programmerID;
    cout << "Connect to the following ID's ";
    cout << "Programmers ID: ";
    cin >> programmerID;
    int computerID;
    cout << "Computers ID: ";
    cin >> computerID;

    pcservice.connectProgrammerToComputer(computerID, programmerID);
}

void ppInterface::displayProgrammerAndComputers(){
     int programmerID;
     cout << "Display connection for programmer with ID :" ;
     cin >> programmerID;
     cout << endl;
     Programmer programmer = pcservice.getProgrammer(programmerID);

            printf("%-4i : %-40s  %-8s  %-4i  %-4s\n",
                   programmer.programmerID,
                   programmer.Name.c_str(),
                   genderToString(programmer.Gender).c_str(),
                   programmer.BirthYear,
                   intToString(programmer.DeadYear).c_str());

    vector<Computer> computers = pcservice.getComputers(programmerID);
     for (unsigned int i = 0; i<computers.size();  i++) {
            printf("%-4i : %-40s - %-45s - %-4s - %-4s\n",
                   computers[i].computerID,
                   computers[i].Name.c_str(),
                   computers[i].Type.c_str(),
                   intToYesNo(computers[i].WasItBuilt).c_str(),
                   intToString(computers[i].YearBuilt).c_str());
    }
}

void ppInterface::displayComputerAndProgrammers(){
     int computerID;
     cout << "Displaying the connection for computers with ID : " ;
     cin >> computerID;
     cout << endl;
     Computer computer = pcservice.getComputer(computerID);

        printf("%-4i : %-40s | %-30s | %-4s | %-4s\n",
            computer.computerID,
            computer.Name.c_str(),
            computer.Type.c_str(),
            intToYesNo(computer.WasItBuilt).c_str(),
            intToString(computer.YearBuilt).c_str());


    vector<Programmer> programmers = pcservice.getProgrammers(computerID);
     for (unsigned int i = 0; i<programmers.size();  i++) {
         printf("%-4i : %-40s | %-30s | %-4i | %-4s\n",
              programmers[i].programmerID,
              programmers[i].Name.c_str(),
              genderToString(programmers[i].Gender).c_str(),
              programmers[i].BirthYear,
              intToString(programmers[i].DeadYear).c_str());
    }
}

void ppInterface::displayAllConnections() {
    vector<Programmer> programmers = pcservice.findProgrammers("");
    vector<Computer> computers;
    cout << "ID   Programmername                  <->  ID    Computername                    Typeanical computer" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
     for (unsigned int i = 0; i<programmers.size();  i++) {


            computers = pcservice.getComputers(programmers[i].programmerID);
             for (unsigned int c = 0; c<computers.size();  c++) {
                    printf("%-4i %-30s  <->  %-4i  %-30s  %-20s\n",
                           programmers[i].programmerID,
                           programmers[i].Name.c_str(),
                           computers[c].computerID,
                           computers[c].Name.c_str(),
                           computers[c].Type.c_str());

        }

     }

}




