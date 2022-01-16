#include<iostream>
#include<iomanip>
#include"Personne.h"
using namespace std;

int Personne::c=0;

// Constructers & Destucters
Personne::Personne(){
    id=++c;
}
Personne::Personne(string ci,string n, string p, string t, string a){
    id=++c;
    cin = ci;
    nom = n;
    prenom = p;
    tele = t;
    adresse = a;
}

// Setters
void Personne::setNom(string n){
    nom = n;
}
void Personne::setPrenom(string p){
    prenom = p;
}
void Personne::setTele(string t){
    tele = t;
}
void Personne::setAdresse(string a){
    adresse = a;
}

// Getters
int Personne::getId(){
    return id;
}
string Personne::getCIN(){
    return cin;
}
string Personne::getNom(){
    return nom;
}
string Personne::getPrenom(){
    return prenom;
}
string Personne::getTele(){
    return tele;
}
string Personne::getAdresse(){
    return adresse;
}
