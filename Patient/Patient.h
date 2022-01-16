#include<iostream>
#include"../Personne/Personne.h"
using namespace std;

class Patient:public Personne{
    string date_naissance;

    public:
    Patient();
    Patient(string,string,string,string,string,string);

    void setDateNaissance(string);
    string getDateNaissance();

    void toString();
};
