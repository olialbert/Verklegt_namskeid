<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
    cout << "H�r � ekki a� vera neitt nema tengining � presintation layer/klasa" << endl;
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

    // TODO b�a til einhverja lykkju me� a�ger�um
	Programmers programmers;
	programmers.add(programmers.read());
    cout << "***** FIND ALL *********"<<endl;
	programmers.findAll("s");


    return 0;
}

>>>>>>> origin/master
