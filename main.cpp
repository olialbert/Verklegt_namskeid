#include <iostream>
#include "ppInterface.h"
using namespace std;


int main()
{
    char choose;  // breyta fyrir val � a�ger�

    cout << "This is a program that contains information about famous computer scientists" << endl; //texti sem �ts�krir hva� forriti� gerir
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
        case '1':                      //  S�nir allan listannn
            ppi.display("");
            break;
        case '2':                      //leita � lista
            ppi.search();
            break;
        case '3':
            ppi.addProgrammer();       //b�tir vi� listann
            break;
        case '4':
           ppi.deleteProgrammer();     //fjarl�gir �r listanum
            break;
        case '5':                      // ra�ar listanum � stafr�fsr��
            ppi.sortProgrammers(1);
            break;
        case '6':                      //  S�nir allan listan ra�a�an eftir kyni og stafr�fsr��
            ppi.sortProgrammers(2);
            break;
        case '7':                      //vistar breytingar � skr�na.
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

