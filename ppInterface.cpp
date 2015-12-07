#include "ppInterface.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
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

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem útsýkrir hvað forritið gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose one of the following actions" << endl;

    string s;
    do{
        cout << endl;
        cout << "1. Display Programmers " << endl;
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
           vector<Programmer> getProgrammers(int computerId);
            break;
        case '2':                      //leita í lista
            search();
            break;
        case '3':
            void addProgrammer(Programmer p);       //bætir við listann
            break;
        case '4':
           void delProgrammer(int programmerId);     //fjarlægir úr listanum
            break;
        case '5':                      // raðar listanum í stafrófsröð
            sortProgrammers(1);
            break;
        case '6':                      //  Sýnir allan listan raðaðan eftir kyni og stafrófsröð
            sortProgrammers(2);
            break;

        default:
            if(choose != '8')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '8');

    return 0;
}

void ppInterface::sortProgrammers() {
    char choose;  // breyta fyrir val á aðgerð
    Programmers programmers;
    string s;
    do{
        cout << endl;
        cout << "Sort by :" << endl;
        cout << "1. Name ascending order" << endl;
        cout << "2. Name descending order" << endl;
        cout << "3. Gender ascending order" << endl;
        cout << "4. Gender descending order" << endl;
        cout << endl;
        cout << "Choose Programmers sorting : ";
        cin >> choose;
        getline(cin, s);

        switch (choose){
        case '1':
            programmers.orderProgrammersBy(PROGRAMMERS_ORDER_NAME);
            break;
        case '2':
            programmers.orderProgrammersBy(PROGRAMMERS_ORDER_NAME_DESC);
            break;
        case '3':
            programmers.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER);
            break;
        case '4':
            programmers.orderProgrammersBy(PROGRAMMERS_ORDER_GENDER_DESC);
            break;
        }
    } while(choose != '1' && choose != '2' && choose != '3' && choose != '4');
}

/*void ppInterface::search() {
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
}*/
