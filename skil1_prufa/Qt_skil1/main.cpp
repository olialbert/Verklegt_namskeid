#include <QCoreApplication>
#include <iostream>
#include "ppInterface.h"
using namespace std;


int main()
{
    char choose; // breyta fyrir val á aðgerð

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem útsýkrir hvað forritið gerir
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Pleas choose one of the following actions" << endl;

    ppInterface ppi;
        string s;
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
        getline(cin, s);

        switch (choose){
        case '1':
            ppi.display("");   //  Sýnir allan listan
            break;
        case '2':
          //  SearchList; // fall sem leifir notendanum að leita í lista
            ppi.search();
            break;
        case '3':
            ppi.readProgrammer();
         //   AddToList; // fall sem leyfi notenandum að bæta við listan
            break;
        case '4':
           ppi.deleteProgrammer();
          //  RemoveFromList; // fall sem leyfir notendanum að fjarlægja úr listanum
            break;
        case '5':
         //   SortList by name; // fall sem leyfir notendanum að endurraða listanum í stafrófsröð
            ppi.sortProgrammers(1);
            break;
        case '6':
            ppi.sortProgrammers(2); //  Sýnir allan listan raðaðan eftir kyni og stafrófsröð
            break;
        case '7':
            ppi.save();
            break;
        default:
            if(choose != '8')
                cout << "Invalid choice" << endl;
            break;
        }
    } while(choose != '8');

    return 0;
}



