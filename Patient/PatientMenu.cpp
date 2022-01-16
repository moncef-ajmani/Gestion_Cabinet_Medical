#include<iostream>
#include"Patient.cpp"
using namespace std;

void patient_menu(){
    int choix,test=1;
    do{
        system("CLS");
        cout<<"------------- Gestion des patients -------------\n";
        cout<<"1 - Ajouter un patient\n";
        cout<<"2 - Modifier un patient\n";
        cout<<"3 - Supprimer un patient\n";
        cout<<"4 - Chercher un patient par CIN\n";
        cout<<"5 - Affiche list des patients\n";
        cout<<"6 - Quitter\n";
        do{
            cout<<"Taper votre choix: ";
            cin>>choix;
        }while(choix>6 || choix <1);

        switch(choix){
            case 1:
                ajouterPatient();
                break;
            case 2:
                modifierPatient();
                break;
            case 3:
                supprimerPatient();
                break;
            case 4:
                chercherPatient();
            case 5:
                afficherPatients();
                break;
            case 6:
                exit(1);
        }
        cout<<"Voulez vous continue? (0/1): ";
        cin>>test;
    }while(test==1);
}
