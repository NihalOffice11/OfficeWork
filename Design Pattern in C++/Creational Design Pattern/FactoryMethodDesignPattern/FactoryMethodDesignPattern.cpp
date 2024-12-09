#include<iostream>
#include<algorithm>
#include "Game.h"
#include "GameFactory.h"
using namespace std;

int main()
{
    
    string str ;
    cout<<"Enter the store name "<<endl;
    cin>>str ;

    Game g;
    unique_ptr<GameFactory> gf = g.getGameStore(str);
    gf->typesOfGames();

}