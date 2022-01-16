#ifndef CONSULTATION_H_INCLUDED
#define CONSULTATION_H_INCLUDED
#include<vector>
#include"../Medecin/Medecin.h"
#include"../Patient/Patient.h"
using namespace std;

class Consultation{
    int id;
    Medecin medecin;
    Patient patient;
    string date;
    string time;
    float montant;

    public:
    static int inc;

    // Constuctors
    Consultation();
    Consultation(Medecin,Patient,string,string,float);

    // Getter & Setters
    void setMedecin(Medecin);
    void setPatient(Patient);
    void setDate(string);
    void setTime(string);
    void setMontant(float);

    int getId();
    Medecin getMedecin();
    Patient getPatient();
    string getDate();
    string getTime();
    float getMontant();

    // Methods
    void toString();

};
int Consultation::inc=0;
vector<Consultation> consultations;
#endif