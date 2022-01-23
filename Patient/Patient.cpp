#include<iostream>
#include<vector>
#include <stdlib.h>
#include<iomanip>
#include<string>
#include "Patient.h"
#include"../utils/Message.cpp"
using namespace std;



// Constructers
Patient::Patient(){}
Patient::Patient(string c,string n, string p, string d, string t, string a){
    cin=c;
    nom = n;
    prenom = p;
    date_naissance = d;
    tele = t;
    adresse = a;
}

// Getters & Setters
void Patient::setDateNaissance(string d){
    date_naissance = d;
}
string Patient::getDateNaissance(){
    return date_naissance;
}

// Methods
void Patient::toString(){
    cout
        << left
        << setw(10)
        << id
        << left
        << setw(10)
        <<cin
        << left
        << setw(20)
        <<nom
        << left
        << setw(20)
        <<prenom
        << left
        << setw(20)
        << date_naissance
        << left
        << setw(20)
        << tele
        << left
        << setw(20)
        <<adresse
        <<endl;
    for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
}

void tablePatientHeader(){
for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
    cout
        << left
        << setw(10)
        << "ID"
        << left
        << setw(10)
        << "CIN"
        << left
        << setw(20)
        << "Nom"
        << left
        << setw(20)
        << "Prenom"
        << left
        << setw(20)
        << "Date naissance"
        << left
        << setw(20)
        << "Tele"
        << left
        << setw(10)
        << "Adresse"
        <<endl;
    for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
}

void ajouterPatient(){
    string n,p,d,a,t,c;
    cout<<"Donner le nom: ";
    cin>>n;
    cout<<"Donner le penom: ";
    cin>>p;
    cout<<"Donner le cin: ";
    cin>>c;
    cout<<"Donner la date de naissance (dd/mm/yyyy): ";
    cin>>d;
    cin.ignore();
    cout<<"Donner l'adresse: ";
    getline(cin,a);
    cout<<"Donner le tele: ";
    cin>>t;
    Patient patient(c,n,p,d,t,a);
    patients.push_back(patient);
    new Message("Patient ajoute avec succes");
}
void afficherPatients(){
    tablePatientHeader();
    for(Patient p : patients){
        p.toString();
    }
}

void modifierPatient(){
    int id;
    afficherPatients();
    cout<<"Donner ID: ";
    cin>>id;
    for(Patient &patient:patients){
        if(patient.getId()==id){
            string n,p,d,a,t;
            cout<<"Donner le nom: ";
            cin>>n;
            cout<<"Donner le penom: ";
            cin>>p;
            cout<<"Donner la date de naissance (dd/mm/yyyy): ";
            cin>>d;
            cin.ignore();
            cout<<"Donner l'adresse: ";
            getline(cin,a);
            cout<<"Donner le tele: ";
            cin>>t;
            patient.setNom(n);
            patient.setPrenom(p);
            patient.setTele(t);
            patient.setAdresse(a);
            patient.setDateNaissance(d);
            new Message("Patient modifie avec succes");
            return;
        }
    }
    new Message("Patient introuvable");
}

void supprimerPatient(){
    int id,i=0;
    afficherPatients();
    cout<<"Donner ID: ";
    cin>>id;
    for(Patient p:patients){
        if(p.getId()==id){
            patients.erase(patients.begin()+i);
            new Message("Patient supprime avec succes");
            return;
        }
        i++;
    }
    new Message("Patient introuvable");
}
void chercherPatient(){
    string CIN;
    cout<<"Donner CIN: ";
    cin>>CIN;
    for(Patient patient: patients){
        if(patient.getCIN()==CIN){
            tablePatientHeader();
            patient.toString();
            break;
        }
    }
}

Patient getPatientById(int id){
    Patient patient;
    for(Patient p : patients){
        if(p.getId()==id){
            patient = p;
            break; 
        }
    }
    return patient;
}