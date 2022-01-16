#include<iostream>
#include"./Patient/PatientMenu.cpp"
#include"./Medecin/MedecinMenu.cpp"
#include"./Statistiques/statistiques.cpp"
#include"./Consultation/ConsultationMenu.cpp"
using namespace std;

int main(){
    int choix, isTrue=1;
    do{
        system("CLS");
        cout<<"------------- Gestion Hospitaliser -------------\n";
        cout<<"1 - Gestion des Patients\n";
        cout<<"2 - Gestion des Medecins\n";
        cout<<"3 - Gestion des Consultations\n";
        cout<<"4 - Consulter les Statistiques\n";
        cout<<"5 - Quitter\n";
        do{
            cout<<"Taper votre choix: ";
            cin>>choix;
        }while(choix>5 || choix <1);

        switch(choix){
            case 1:
                patient_menu();
                break;
            case 2:
                medecin_menu();
                break;
            case 3:
                consultation_menu();
                break;
            case 4:
                statistiques_menu();
                break;
            case 5:
                exit(1);
        }
        cout<<"Voulez vous continue? (0/1): ";
        cin>>isTrue;
    }while(isTrue==1);
    return 0;
}