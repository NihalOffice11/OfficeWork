#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;

class Chair {
    public:
        ~Chair(){

        }
        virtual void sitOn() = 0;
};
class ModernChair : public Chair{
    public:
        void sitOn(){
            cout<<"I am sitting on the Gaming Chair (Modern) "<<endl;
        }
};
class VictorianChair : public Chair{
    public:
        void sitOn(){
            cout<<"I am sitting on the Throne Chair (Victorian) "<<endl;
        }
};
class ArtDecoChair : public Chair{
    public:
        void sitOn(){
            cout<<"I am sitting on the Normal Art Chair (ArtDeco) "<<endl;
        }
};




class Sofa {
    public:
        ~Sofa(){

        }
        virtual void lieOn() = 0;
};
class ModernSofa : public Sofa{
    public:
        void lieOn(){
            cout<<"I am lying on the Customizable Sofa (Modern) "<<endl;
        }
};
class VictorianSofa : public Sofa{
    public:
        void lieOn(){
            cout<<"I am lying on the King Size Sofa (Victorian)"<<endl;
        }
};
class ArtDecoSofa : public Sofa{
    public:
        void lieOn(){
            cout<<"I am lying on the Normal Sofa (ArtDeco) "<<endl;
        }
};




class coffeeTable{
    public:
        ~coffeeTable(){

        }
        virtual void coffee() = 0;
};
class ModernCoffeeTable : public coffeeTable{
    public:
        void coffee(){
            cout<<"I am making Capiccino On Modern Coffee Table "<<endl;
        }
};
class VictorianCoffeeTable : public coffeeTable{
    public:
        void coffee(){
            cout<<"I am making Expresso On Victorian Coffee Table "<<endl;
        }
};
class ArtDecoCoffeeTable : public coffeeTable{
    public:
        void coffee(){
            cout<<"I am making Latte On ArtDeco Coffee Table "<<endl;
        }
};






class FunitureFactory{
    public:
        virtual unique_ptr<Chair> createChair() = 0;
        virtual unique_ptr<Sofa> createSofa() = 0;
        virtual unique_ptr<coffeeTable> createCoffeeTable() = 0;

        virtual ~FunitureFactory(){

        } 
};

class ModernFactory : public FunitureFactory{
    public:
        unique_ptr<Chair> createChair(){
            return make_unique<ModernChair>();
        }

        unique_ptr<Sofa> createSofa(){
            return make_unique<ModernSofa>();
        }

        unique_ptr<coffeeTable> createCoffeeTable(){
            return make_unique<ModernCoffeeTable>();
        }
};

class VictorianFactory : public FunitureFactory{
    public:
        unique_ptr<Chair> createChair(){
            return make_unique<VictorianChair>();
        }

        unique_ptr<Sofa> createSofa(){
            return make_unique<VictorianSofa>();
        }

        unique_ptr<coffeeTable> createCoffeeTable(){
            return make_unique<VictorianCoffeeTable>();
        }
};

class ArtDecoFactory : public FunitureFactory{
    public:
        unique_ptr<Chair> createChair(){
            return make_unique<ArtDecoChair>();
        }

        unique_ptr<Sofa> createSofa(){
            return make_unique<ArtDecoSofa>();
        }

        unique_ptr<coffeeTable> createCoffeeTable(){
            return make_unique<ArtDecoCoffeeTable>();
        }
};


class AbstractFactoryClient {
    public:
    void getFunitureSet(unique_ptr<FunitureFactory>& factory){
        auto chair = factory->createChair();
        auto sofa = factory->createSofa();
        auto coffeeTable = factory->createCoffeeTable();

        chair->sitOn();
        sofa->lieOn();
        coffeeTable->coffee();
    }
};

int main()
{
    unique_ptr<FunitureFactory> fact;
    AbstractFactoryClient afc;
    
    fact = make_unique<ModernFactory>();
    afc.getFunitureSet(fact);

    cout<<endl;

    fact = make_unique<VictorianFactory>();
    afc.getFunitureSet(fact);

    cout<<endl;

    fact = make_unique<ArtDecoFactory>();
    afc.getFunitureSet(fact);

    cout<<endl;
    return 0;
}