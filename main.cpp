<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
    cout << "Hér á ekki að vera neitt nema tengining í presintation layer/klasa" << endl;
    return 0;
}
=======
//#include <QCoreApplication>
#include "Programmers.h"
using namespace std;


int main()
{
  //stringset dataDoc;
  //readString(dataDoc, "data.txt");

    // TODO búa til einhverja lykkju með aðgerðum
	Programmers programmers;
	programmers.add(programmers.read());
    cout << "***** FIND ALL *********"<<endl;
	programmers.findAll("s");


    return 0;
}

>>>>>>> origin/master
