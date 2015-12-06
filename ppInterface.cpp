#include "ppInterface.h"
#include "utilities/utils.h"
#include <stdio.h>
#include <string>

using namespace utils;
using namespace std;

ppInterface::ppInterface()
{

}

int ppInterface::start() {
    char choose;  // breyta fyrir val á aðgerð

    cout << "lalalalalalaThis is a program that contains information about famous computer scientists" << endl; //texti sem útsýkrir hvað forritið gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose one of the following actions" << endl;

    string s;
    do{
        cout << endl;
        cout << "1. Display list " << endl;
        cout << "2. Search list" << endl;
        cout << "3. Add to list" << endl;
        cout << "4. Remove from list" << endl;
        cout << "5. Sort list by name" << endl;
        cout << "6. Sort list by gender" << endl;
        cout << "7. save changes" << endl;
        cout << "8. Quit" << endl;
        cout << endl;
        cout << "Choose action : ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':                      //  Sýnir allan listannn
            display("");
            break;
        case '2':                      //leita í lista
            search();
            break;
        case '3':
            addProgrammer();       //bætir við listann
            break;
        case '4':
           deleteProgrammer();     //fjarlægir úr listanum
            break;
        case '5':                      // raðar listanum í stafrófsröð
            sortProgrammers(1);
            break;
        case '6':                      //  Sýnir allan listan raðaðan eftir kyni og stafrófsröð
            sortProgrammers(2);
            break;
        case '7':                      //vistar breytingar í skrána.
            save();
            break;
        default:
            if(choose != '8')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '8');

    return 0;
}

void ppInterface::search() {
    string sSearch;
    cout << "Search for : ";
    cin >> sSearch;
    display(sSearch);
}

string fmt(string s, int len) {
    return (s + "                        ").substr(0,len);
}
void ppInterface::displayProgrammers(string sSearch) {
    vector<Programmer> programmers = domain.findProgrammers;
     for (unsigned int i = 0; i<v.size();  i++) {
            printf("%-2i : %-40s - %-8s - %-4s - %-4s\n",
                   (i+1),
                   programmers.getProgrammer(v[i]).Name.c_str(),
                   genderToString(programmers.getProgrammer(v[i]).Gender).c_str(),
                   intToString(programmers.getProgrammer(v[i]).BirthYear).c_str(),
                   intToString(programmers.getProgrammer(v[i]).DeadYear).c_str());
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

    programmers.add(p);
}
void ppInterface::save(){
    programmers.save();
}
void ppInterface::deleteProgrammer(){
    int deleteNum;
    cout << "Delete programmer number? ";
    cin >> deleteNum;
    programmers.del(deleteNum);
}
void ppInterface::sortProgrammers(int type){
    if(type==2){
        programmers.sortByGender();
    }
    else{
        programmers.sortByName();    // default
    }
    display("");
}
