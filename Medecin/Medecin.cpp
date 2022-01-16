#include<iostream>
#include"Medecin.h"
using namespace std;

// Contructors
Medecin::Medecin(){}
Medecin::Medecin(string c,string n,string p,string t,string a,string s){
    nom = n;
    prenom = p;
    cin=c;
    tele = t;
    adresse = a;
    specialite = s;
}

// Getters & Setters
void Medecin::setSpecialite(string s){
    specialite = s;
}
string Medecin::getSpecialite(){
    return specialite;
}

void Medecin::toString(){
    cout
        << left
        << setw(10)
        <<id
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
        << tele
        << left
        << setw(20)
        <<adresse
        << left
        << setw(20)
        <<specialite
        <<endl;
    for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
}

vector<Medecin> medecins;

void afficherMedecins(){
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
        << "Tele"
        << left
        << setw(20)
        << "Adresse"
        << left
        << setw(20)
        << "Specialite"
        <<endl;
    for(int i=1;i<120;i++){
        cout<<"-";
    }
    cout<<endl;
    for(Medecin medecin : medecins){
        medecin.toString();
    }
}

void ajouterMedecin(){
    string n,p,s,a,t,c;
    cout<<"Donner le nom: ";
    cin>>n;
    cout<<"Donner le penom: ";
    cin>>p;
    cout<<"Donner le cin: ";
    cin>>c;
    cout<<"Donner la specialite: ";
    cin>>s;
    cin.ignore();
    cout<<"Donner l'adresse: ";
    getline(cin,a);
    cout<<"Donner le tele: ";
    cin>>t;

    Medecin medecin(c,n,p,t,a,s);
    medecins.push_back(medecin);
    new Message("Medecin ajoute avec succes");
}

void modifierMedecin(){
    int id;
    afficherMedecins();
    cout<<"Donner ID: ";
    cin>>id;
    for(Medecin medecin:medecins){
        if(medecin.getId()==id){
            string n,p,d,a,t;
            cout<<"Donner le nom: ";
            cin>>n;
            cout<<"Donner le penom: ";
            cin>>p;
            cin.ignore();
            cout<<"Donner l'adresse: ";
            getline(cin,a);
            cout<<"Donner le tele: ";
            cin>>t;
            medecin.setNom(n);
            medecin.setPrenom(p);
            medecin.setTele(t);
            medecin.setAdresse(a);
            new Message("Medecin modifie avec succes");
        }
    }
    new Message("Medecin introuvable");
}

void supprimerMedecin(){
    int id;
    afficherMedecins();
    cout<<"Donner ID: ";
    cin>>id;
    for(Medecin medecin:medecins){
        if(medecin.getId()==id){
            medecins.erase(medecins.begin()+id-1);
            new Message("Medecin supprime avec succes");
            return;
        }
    }
    new Message("Medecin introuvable");
}
void chercherMedecin(){
    string CIN;
    cout<<"Donner CIN: ";
    cin>>CIN;
    for(Medecin medecin: medecins){
        if(medecin.getCIN()==CIN){
            medecin.toString();
        }
    }
    new Message("medecin supprime avec succes");
}

Medecin getMedecinById(int id){
    Medecin medecin;
    for(Medecin m:medecins){
        if(m.getId()==id){
            medecin = m;
            break; 
        }
    }
    return medecin;
}