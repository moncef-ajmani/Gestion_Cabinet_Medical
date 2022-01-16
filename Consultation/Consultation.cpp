#include<iostream>
#include<vector>
#include"Consultation.h"
using namespace std;



// Constuctors
Consultation::Consultation(){
    id=++inc;
}
Consultation::Consultation(Medecin m,Patient p,string d,string t,float mt){
    id = ++inc;
    medecin = m;
    patient = p;
    date = d;
    time = t;
    montant = mt;
}

// Getter & Setters
void Consultation::setMedecin(Medecin m){
    medecin = m;
}
void Consultation::setPatient(Patient p){
    patient = p;
}
void Consultation::setDate(string d){
    date = d;
}
void Consultation::setTime(string t){
    time = t;
}
void Consultation::setMontant(float m){
    montant = m;
}

int Consultation::getId(){
    return id; 
}

Medecin Consultation::getMedecin(){
    return medecin; 
}
Patient Consultation::getPatient(){
    return patient;
}
string Consultation::getDate(){
    return date;
}
string Consultation::getTime(){
    return time;
}
float Consultation::getMontant(){
    return montant;
}

void Consultation::toString(){
    cout
        << left
        << setw(10)
        << id
        << left
        << setw(20)
        << medecin.getNom()<<" "<<medecin.getPrenom()
        << left
        << setw(20)
        << patient.getNom()<<" "<<patient.getPrenom()
        << left
        << setw(20)
        << date
        << left
        << setw(20)
        << time
        << left
        << setw(10)
        << montant
        <<endl;
    for(int i=1;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
}


void afficherConsultations(){
    for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
    cout
        << left
        << setw(10)
        << "ID"
        << left
        << setw(20)
        << "Medecin"
        << left
        << setw(20)
        << "Patient"
        << left
        << setw(20)
        << "Date"
        << left
        << setw(20)
        << "Time"
        << left
        << setw(10)
        << "Montant"
        <<endl;
    for(int i=1;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
    for(Consultation consultation : consultations){
        consultation.toString();
    }
}

void ajouterConsultation(){
    Patient p;
    Medecin m;
    int id;
    string date,time;
    float montant;

    cout<<"Tableau des patients:\n";
    afficherPatients();
    cout<<"Donner ID du patient: ";
    cin>> id;
    p = getPatientById(id);
    cout<<"Tableau des patients:\n";
    afficherMedecins();
    cout<<"Donner ID du medecin: ";
    cin>> id;
    m = getMedecinById(id);
    cout<<"Donner la date (dd/mm/yyyy): ";
    cin>>date;
    cout<<"Donner l'heur: (hh:mm)";
    cin>>time;
    cout<<"Donner le montant: ";
    cin>>montant;

    Consultation c(m,p,date,time,montant);
    consultations.push_back(c);
    new Message("Consultation ajoute avec succes");
}

void modifierConsultation(){
    Patient p;
    Medecin m;
    int id;
    string date,time;
    float montant;

    afficherConsultations();
    cout<<"Donner ID: ";
    cin>>id;

    for(Consultation c:consultations){
        if(c.getId()==id){
            int idd;
            cout<<"Tableau des patients:\n";
            afficherPatients();
            cout<<"Donner ID du patient: ";
            cin>> idd;
            p = getPatientById(idd);
            cout<<"Tableau des patients:\n";
            afficherMedecins();
            cout<<"Donner ID du medecin: ";
            cin>> idd;
            m = getMedecinById(id);
            cout<<"Donner la date (dd/mm/yyyy): ";
            cin>>date;
            cout<<"Donner l'heur: (hh:mm)";
            cin>>time;
            cout<<"Donner le montant: ";
            cin>>montant;

            c.setMedecin(m);
            c.setMontant(montant);
            c.setPatient(p);
            c.setTime(time);
            c.setDate(date);
            new Message("Consultation modifie avec succes");
        }
    }
}

void supprimerConsultation(){
    int id;
    afficherConsultations();
    cout<<"Donner ID: ";
    cin>>id;
    for(Consultation c:consultations){
        if(c.getId()==id){
            consultations.erase(consultations.begin()+id-1);
            new Message("Consultation supprime avec succes");
            return;
        }
    }
    new Message("Consultation introuvable");

}

void getConsultationsByPatientCin(){
    string CIN;
    for(Consultation c:consultations){
        if(c.getPatient().getCIN()==CIN){
            c.toString();
        }
    }
}

void getConsultationsByMedecinCin(){
    string CIN;
    for(Consultation c:consultations){
        if(c.getMedecin().getCIN()==CIN){
            c.toString();
        }
    }
}

float getRevenuTotal(){
    float somme=0;
    for(Consultation c:consultations){
        somme+=c.getMontant();
    }
    return somme;
}