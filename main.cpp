#include "functions.h"
#include <iostream>
#include "Programmers.h"
using namespace std;


int main()
{
    int choose; // breita fyrir val � a�ger�

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem �ts�krir hva� forriti� gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose a number of one of the following actions" << endl;
    cout << endl;
    cout << "1. Display list " << endl;
    cout << "2. Search list" << endl;
    cout << "3. Add to list" << endl;
    cout << "4. Remove from list" << endl;
    cout << "5. Sort list" << endl;
    cout << "6. Quit" << endl;
    cout << endl;


    Programmers programmers;

    do{
        int deleteNum = 0;
        cout << "I choose the number ";
        cin >> choose;
        switch (choose){
        case 1:
            programmers.findAll(" ");   //  S�nir allan listan
            break;
        case 2:
          //  SearchList; // fall sem leifir notendanum a� leita � lista
            break;
        case 3:
            programmers.read();
         //   AddToList; // fall sem leifi notenandum a� b�ta vi� listan
            break;
        case 4:
            cout << "Delete person number? ";
            cin >> deleteNum;
            programmers.rem(deleteNum);
          //  RemoveFromList; // fall sem leifir notendanum a� fjarl�gja �r listanum
            break;
        case 5:
         //   SortList; // fall sem leifir notendanum a� endurra�a listanum
            break;
        case 6:
            programmers.save();
            break;
        default:
            if(choose != 6)
                cout << "Invalid choice" << endl;
            break;
        }
    }while(choose != 6);

  //stringset dataDoc;
  //readString(dataDoc, "data.txt");

    // TODO b�a til einhverja lykkju me� a�ger�um




    return 0;
}

