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

void ppInterface::search() { //Function that looks for a string in our .txt file
    string sSearch;
    cout << "Search for : ";
    cin >> sSearch;
    display(sSearch);
}

string fmt(string s, int len) {
    return (s + "                        ").substr(0,len); // Ekki viss hvað þetta gerir ???????????????
}
void ppInterface::display(string sSearch) { // displays the whole list of Computer Scientists that is in the .txt file
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

void ppInterface::readProgrammer() {  //writes down the info about the new programmer that the user puts inn and adds it to the .txt file

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
void ppInterface::save(){ // saves the changes that have been made
    programmers.save();
}
void ppInterface::deleteProgrammer(){ //function that Deletes the sentens wich has the number you type in
    int deleteNum;
    cout << "Delete programmer number? ";
    cin >> deleteNum;
    programmers.del(deleteNum);
}
void ppInterface::sortProgrammers(int type){ // Sorts the list of programmers by gender
    if(type==2){
        programmers.sortByGender();
    }
    else{
        programmers.sortByName();    // default  // Sorts the list of programmers by Name
    }
    display("");
}
