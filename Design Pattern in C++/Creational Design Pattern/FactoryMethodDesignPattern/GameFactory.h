#ifndef Game_Fact
#define Game_Fact

class GameFactory{
    public:
        virtual ~GameFactory() = default;
        virtual void typesOfGames() = 0;
};



#endif 