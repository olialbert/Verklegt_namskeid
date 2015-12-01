#include <iostream>
#include "Programmers.h"
using namespace std;


int main()
{
    char choose; // breyta fyrir val � a�ger�

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem �ts�krir hva� forriti� gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose one of the following actions" << endl;


    Programmers programmers;

    int deleteNum = 0;
    string sSearch = "";
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

        deleteNum = 0;
        sSearch = "";
        switch (choose){
        case '1':
            programmers.Display("");   //  S�nir allan listan
            break;
        case '2':
          //  SearchList; // fall sem leifir notendanum a� leita � lista
            cout << "Search for : ";
            cin >> sSearch;
            programmers.Display(sSearch);
            break;
        case '3':
            programmers.read();
         //   AddToList; // fall sem leyfi notenandum a� b�ta vi� listan
            break;
        case '4':
            cout << "Delete person number? ";
            cin >> deleteNum;
            programmers.del(deleteNum);
          //  RemoveFromList; // fall sem leyfir notendanum a� fjarl�gja �r listanum
            break;
        case '5':
         //   SortList by name; // fall sem leyfir notendanum a� endurra�a listanum � stafr�fsr��
            programmers.sortListByName();
            break;
        case '6':
            programmers.sortListByGender(); //  S�nir allan listan ra�a�an eftir kyni og stafr�fsr��
            break;

        case '7':
            programmers.save();
            break;
        default:
            if(choose != '8')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != 8);

  //stringset dataDoc;
  //readString(dataDoc, "data.txt");

    // TODO b�a til einhverja lykkju me� a�ger�um




    return 0;
}

