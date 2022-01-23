#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED
#include"../Personne/Personne.cpp"
using namespace std;

class Medecin:public Personne{
    string specialite;

    public:
    Medecin();
    Medecin(string,string,string,string,string,string);

    void setSpecialite(string);
    string getSpecialite();

    void toString();
};
vector<Medecin> medecins;
#endif
