#ifndef Game_H
#define Game_H

#include "GameFactory.h"
#include "Steam.h"
#include "Epic.h"
#include "UbisoftConnect.h"
#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Game{
    public:
        unique_ptr<GameFactory>  getGameStore(string store){
            if(store == "Steam"){
                return make_unique<Steam>();
            }
            else if(store == "Epic"){
                return make_unique<Epic>();
            }
            else if(store == "UbisoftConnect"){
                return make_unique<UbisoftConnect>();
            }

            return nullptr;
        }
};

#endif // 