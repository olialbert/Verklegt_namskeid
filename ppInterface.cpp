#include "ppInterface.h"
#include <stdio.h>
#include <string>

ppInterface::ppInterface()
{

}

ppInterface::~ppInterface()
{
    //dtor
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
void ppInterface::display(string sSearch) {
    vector<int> v;
    programmers.Find(v, sSearch);
    for (unsigned int i = 0; i<v.size();  i++) {
            printf("%-2i : %-40s - %-1s - %-4s - %-4s\n",
                   (i+1),
                   programmers.getProgrammer(v[i]).Name.c_str(),
                   programmers.getProgrammer(v[i]).Gender.c_str(),
                    programmers.getProgrammer(v[i]).BirthYear.c_str(),
                    programmers.getProgrammer(v[i]).DeadYear .c_str());
            /*cout << (i+1) << " : " <<
                    programmers.getProgrammer(v[i]).Name << " - " <<
                    programmers.getProgrammer(v[i]).Gender << " - " <<
                    programmers.getProgrammer(v[i]).BirthYear << " - " <<
                    programmers.getProgrammer(v[i]).DeadYear << endl;*/
    }
}

void ppInterface::readProgrammer() {

    Programmer p;

    cout << "Name     : " ;
    getline(cin, p.Name);

    cout << "Gender   : " ;
    getline(cin, p.Gender);

    cout << "BirthYear : " ;
    getline(cin, p.BirthYear);

    cout << "Dead     : " ;
    getline(cin, p.DeadYear);

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
}
