#include<iostream>
#include"Medecin.h"
#include"../utils/tableHeader.cpp"
using namespace std;

// Table Header 
string header[] = {"ID","CIN","Nom","Prenom","Tele","Adresse","Specialite"};
int size = *(&header +1) - header;
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
        << setw(20)
        <<id
        << left
        << setw(20)
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
    for(int i=1;i<size*20;i++){
        cout<<"-";
    }
    cout<<endl;
}

void afficherMedecins(){
    tableHeader(header,size);
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
    for(Medecin &medecin:medecins){
        if(medecin.getId()==id){
            string n,p,d,a,t,s;
            cout<<"Donner le nom: ";
            cin>>n;
            cout<<"Donner le penom: ";
            cin>>p;
            cin.ignore();
            cout<<"Donner l'adresse: ";
            getline(cin,a);
            cout<<"Donner le tele: ";
            cin>>t;
            cout<<"Donner Specialite: ";
            cin>>s;
            medecin.setNom(n);
            medecin.setPrenom(p);
            medecin.setTele(t);
            medecin.setAdresse(a);
            medecin.setSpecialite(s);
            new Message("Medecin modifie avec succes");
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
            tableHeader(header,size);
            medecin.toString();
            break;
        }
    }

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