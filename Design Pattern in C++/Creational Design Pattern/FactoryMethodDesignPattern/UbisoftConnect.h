#ifndef Ubisoft_h
#define Ubisoft_h

#include "GameFactory.h"
#include<iostream>

using namespace std;

class UbisoftConnect : public GameFactory{
    public:

        UbisoftConnect(){
            
        }

        void typesOfGames(){
            cout<<"For Honor, Assassin Creed Unity , Crew 2, Assassin Creed Chronicles ,The Division "<<endl;
        }
};


#endif