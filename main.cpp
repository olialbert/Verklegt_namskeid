#include <iostream>
#include "Programmers.h"
using namespace std;


int main()
{
    char choose; // breyta fyrir val á aðgerð

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem útsýkrir hvað forritið gerir
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
            programmers.Display("");   //  Sýnir allan listan
            break;
        case '2':
          //  SearchList; // fall sem leifir notendanum að leita í lista
            cout << "Search for : ";
            cin >> sSearch;
            programmers.Display(sSearch);
            break;
        case '3':
            programmers.read();
         //   AddToList; // fall sem leyfi notenandum að bæta við listan
            break;
        case '4':
            cout << "Delete person number? ";
            cin >> deleteNum;
            programmers.del(deleteNum);
          //  RemoveFromList; // fall sem leyfir notendanum að fjarlægja úr listanum
            break;
        case '5':
         //   SortList by name; // fall sem leyfir notendanum að endurraða listanum í stafrófsröð
            programmers.sortListByName();
            break;
        case '6':
            programmers.sortListByGender(); //  Sýnir allan listan raðaðan eftir kyni og stafrófsröð
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

    // TODO búa til einhverja lykkju með aðgerðum




    return 0;
}

