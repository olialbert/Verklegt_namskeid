#include "functions.h"
#include <iostream>
#include "Programmers.h"
using namespace std;


int main()
{
    int choose; // breita fyrir val á aðgerð

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem útsýkrir hvað forritið gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose a number of one of the following actions" << endl;
    cout << endl;
    cout << "1. Display list " << endl;
    cout << "2. Search list" << endl;
    cout << "3. Add to list" << endl;
    cout << "4. Remove from list" << endl;
    cout << "5. Sort list" << endl;
    cout << endl;


    Programmers programmers;

    do{
        cout << "I choose the number ";
        cin >> choose;
        switch (choose){
        case 1:
            programmers.findAll(" ");
          //  DisplayList; // fall sem sýnir allan listan
            break;
        case 2:
          //  SearchList; // fall sem leifir notendanum að leita í lista
            break;
        case 3:
            programmers.read();
         //   AddToList; // fall sem leifi notenandum að bæta við listan
            break;
        case 4:
          //  RemoveFromList; // fall sem leifir notendanum að fjarlægja úr listanum
            break;
        case 5:
         //   SortList; // fall sem leifir notendanum að endurraða listanum
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }while(choose != 0);



  //stringset dataDoc;
  //readString(dataDoc, "data.txt");

    // TODO búa til einhverja lykkju með aðgerðum

	//programmers.add(programmers.read());
    cout << "***** FIND ALL *********"<<endl;
	programmers.findAll("s");
    return 0;
}

