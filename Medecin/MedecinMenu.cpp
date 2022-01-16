#include<iostream>
#include"../Medecin/Medecin.cpp"
using namespace std;

void medecin_menu(){

    int choix,test=1;
    do{
        system("CLS");
        cout<<"------------- Gestion des medecins -------------\n";
        cout<<"1 - Ajouter un medecin\n";
        cout<<"2 - Modifier un medecin\n";
        cout<<"3 - Supprimer un medecin\n";
        cout<<"4 - Chercher un medecin par CIN\n";
        cout<<"5 - Affiche list des medecins\n";
        cout<<"6 - Quitter\n";
        do{
            cout<<"Taper votre choix: ";
            cin>>choix;
        }while(choix>6 || choix <1);

        switch(choix){
            case 1:
                ajouterMedecin();
                break;
            case 2:
                modifierMedecin();
                break;
            case 3:
                supprimerMedecin();
                break;
            case 4:
                chercherMedecin();
                break;
            case 5:
                afficherMedecins();
                break;
            case 6:
                return;
        }
        cout<<"Voulez vous continue? (0/1): ";
        cin>>test;
    }while(test==1);
}