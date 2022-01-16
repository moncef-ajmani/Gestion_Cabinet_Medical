#include<iostream>
using namespace std;

class Message{
    public:
    string msg;

    Message(){}
    Message(string m){
        msg = m;
        toString();
    }

    void toString(){
        int size = msg.length()+8*2;
        for(int i=0;i<size;i++){
           cout<<"-"; 
        }
        cout<<"\n";
        cout<<"\t"<<msg<<"\t\n";
        for(int i=0;i<size;i++){
           cout<<"-"; 
        }
        cout<<endl;
    }
};