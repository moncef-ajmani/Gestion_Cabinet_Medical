#include<iostream>
#include <stdlib.h>
#include"./Medecin/MedecinMenu.cpp"
#include"./Patient/PatientMenu.cpp"
using namespace std;

int main(){
    int choix, isTrue=1;
    do{
        system("CLS");
        cout<<"------------- Gestion Hospitaliser -------------\n";
        cout<<"1 - Gestion des patients\n";
        cout<<"2 - Gestion des Medecins\n";
        cout<<"3 - Quitter\n";
        do{
            cout<<"Taper votre choix: ";
            cin>>choix;
        }while(choix>3 || choix <1);

        switch(choix){
            case 1:
                patient_menu();
            case 2:
                medecin_menu();
            case 3:
                exit(1);
        }
        cout<<"Voulez vous continue? (0/1): ";
        cin>>isTrue;
    }while(isTrue==1);
    
    return 0;
}