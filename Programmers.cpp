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
    pFile.open("Programmers.txt");
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
   ofstream output;
   output.open("Programmers.txt");
    for (unsigned int i=0; i<programmers.size();i++) {
        output << programmers[i].Name << ";" <<  programmers[i].Gender << ";" <<  programmers[i].Birthday << ";" <<  programmers[i].Deadday << endl;
    }
    output.close();
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
}

void Programmers::rem(int remNum) {
    programmers.erase(programmers.begin()+(remNum-1));
}

void Programmers::findAll(string sSearch) {
    for (unsigned int i=0; i<programmers.size();i++) {
        //if (programmers[i].Name.find(sSearch) != string::npos) { // string::npos ef sSearch finnst ekki
            cout << i+1 << ". " << programmers[i].Name << " - " << programmers[i].Gender << " - " << programmers[i].Birthday << endl;

    }
}

