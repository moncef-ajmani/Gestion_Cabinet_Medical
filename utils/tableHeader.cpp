#include<iostream>
#include<iomanip>
using namespace std;

void tableHeader(string tab[],int n){
    for(int i=1;i<n*20;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout
        << left
        << setw(20)
        << tab[i];
    }
    cout<<endl;
    for(int i=1;i<n*20;i++){
        cout<<"-";
    }
    cout<<endl;
}