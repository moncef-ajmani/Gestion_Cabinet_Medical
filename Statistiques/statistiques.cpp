#include<iostream>
#include"../Patient/Patient.h"
#include"../Medecin/Medecin.h"
#include"../Consultation/Consultation.h"

using namespace std;

void statistiques_menu(){
    system("CLS");
    cout<<"------------- Statistiques -------------\n";
    cout<<"Total des patients: "<<patients.size()<<endl;
    cout<<"Total des medecins: "<<medecins.size()<<endl;
    cout<<"Total des consultations: "<<consultations.size()<<endl;
    float somme=0;
    for(Consultation c:consultations){
        somme+=c.getMontant();
    }
    cout<<"Revenu Total: "<<somme<<endl;
    
}