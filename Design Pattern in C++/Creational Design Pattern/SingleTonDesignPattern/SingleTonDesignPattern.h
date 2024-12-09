#ifndef single_H
#define single_H

#include<iostream>
using namespace std;

class Government{
    private:
        static Government* instance;
        string party;
        

        Government(string& party){
            this->party = party;
            cout<<"Government object created (single)"<<endl;
        }

    public:
        static int count ;
        static Government* getInstance(string party){
            if(instance == NULL){
                instance = new Government(party);
                
            }
            return instance;
        }

        void selectedGovernment(){
            cout<<"Government selected : "<<party<<endl;
            count++;
        }

        ~Government(){
            cout<<"Government has Fallen (object destroyed) "<<endl;
        }
};

Government* Government :: instance = nullptr;
int Government :: count = 0;

#endif