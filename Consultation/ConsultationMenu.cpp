#include<iostream>
#include <stdlib.h>
#include"Consultation.cpp"
using namespace std;

void consultation_menu(){
    int choix,test=1;
    do{
        system("CLS");
        cout<<"------------- Gestion des consultation -------------\n";
        cout<<"1 - Ajouter une consultation\n";
        cout<<"2 - Modifier une consultation\n";
        cout<<"3 - Afficher les consultations\n";
        cout<<"4 - Filtrer les consultation par CIN du medecin \n";
        cout<<"5 - Filtrer les consultation par CIN du patient \n";
        cout<<"6 - Quitter\n";
        do{
            cout<<"Taper votre choix: ";
            cin>>choix;
        }while(choix>6 || choix <1);

        switch(choix){
            case 1:
                ajouterConsultation();
                break;
            case 2:
                modifierConsultation();
                break;
            case 3:
                afficherConsultations();
                break;
            case 4:
                getConsultationsByMedecinCin();
                break;
            case 5:
                getConsultationsByPatientCin();
                break;
            case 6:
                return;
        }
        cout<<"Voulez vous continue? (0/1): ";
        cin>>test;
    }while(test==1);
}