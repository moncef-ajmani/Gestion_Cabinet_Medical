#include<iostream>
using namespace std;

class Personne{
    protected:
    int id;
    string cin;
    string nom;
    string prenom;
    string tele;
    string adresse;

    public:
    static int c;
    // Constructers & Destucters
    Personne();
    Personne(string,string,string,string,string);

    // Setters
    void setCIN(string);
    void setNom(string);
    void setPrenom(string);
    void setTele(string);
    void setAdresse(string);

    // Getters 
    int getId();
    string getCIN();
    string getNom();
    string getPrenom();
    string getTele();
    string getAdresse();

};
int Personne::c=0;