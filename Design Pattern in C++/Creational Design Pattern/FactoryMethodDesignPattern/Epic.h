#ifndef Epic_h
#define Epic_h

#include "GameFactory.h"
#include<iostream>

using namespace std;

class Epic : public GameFactory{
    public:

        Epic(){
            
        }
        void typesOfGames(){
            cout<<"Control,Among us,GodFall,Crew 2 are on the Epic Platform"<<endl;
        }
};

#endif