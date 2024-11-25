#ifndef Steam_H
#define Steam_H

#include "GameFactory.h"
#include <iostream>

using namespace std;

class Steam : public GameFactory{
    public: 

        Steam(){

        }

        void typesOfGames(){
            cout<<"Fortnite,Fall Guys,Counter Strike Global Offensive , Tell me Why are in the Steam Platform"<<endl;
        }
};




#endif