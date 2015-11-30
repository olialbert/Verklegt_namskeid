#include "Programmers.h"
#include <iostream>
#include <fstream>

Programmers::Programmers() {
    load();
}

// loads all scientists from text file
// format name;gender;birthday
void Programmers::load() {
    ifstream pFile;
    pFile.open("programmers.txt");
    if(pFile.fail()){
        cout << "error" << endl;
        return;
    }
    Programmer p;
    string line;
    while (getline(pFile, line)) {
        p.Name = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.Gender = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.Birthday = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);
        p.Deadday = line.substr(0,line.find(";"));
        line = line.substr(line.find(";")+1);

        add(p);
    }
    pFile.close();
}
void Programmers::save() {
    // write all to programmers.txt
    for (int i=0; i<programmers.size();i++) {
        // TODO write to file
    }
}
Programmer Programmers::read() {
    Programmer p;
    cout << "Name     : " ;
    cin >> p.Name;

    cout << "Gender   : " ;
    cin >> p.Gender;

    cout << "Birthday : " ;
    cin >> p.Birthday;

    cout << "Dead     : " ;
    cin >> p.Deadday;

    add(p);
    return p;
}

void Programmers::add(Programmer p) {
    programmers.push_back(p);
    save();
}

void Programmers::findAll(string sSearch) {
    for (int i=0; i<programmers.size();i++) {
        //if (programmers[i].Name.find(sSearch) != string::npos) { // string::npos ef sSearch finnst ekki
            cout << i+1 << ". " << programmers[i].Name << " - " << programmers[i].Gender << " - " << programmers[i].Birthday << endl;

    }
}

