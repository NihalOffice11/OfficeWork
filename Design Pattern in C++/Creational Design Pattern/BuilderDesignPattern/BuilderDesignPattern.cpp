#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

// Common Construction
class Gun
{
private:
    string stock;
    string muzzle;
    int noOfBullets;
    bool foregrip;
    string sight;

public:
    Gun() {}

    void setStock(string stock) { this->stock = stock; }
    void setMuzzle(string muzzle) { this->muzzle = muzzle; }
    void setNoOfBullets(int noOfBullets) { this->noOfBullets = noOfBullets; }
    void setForeGrip(bool foregrip) { this->foregrip = foregrip; }
    void setSight(string sight) { this->sight = sight; }

    void previewGun()
    {
        cout << "Gun specifications : " << endl;
        cout << "Stock : " << stock << endl
             << "Muzzle Type: " << muzzle << endl
             << "Magazine_Size: " << noOfBullets << endl
             << "ForeGrip: " << (foregrip ? "Yes" : "No") << endl
             << "Sight: " << sight << endl;
    }
};

// Step to build gun
class BuildingGun {
public:
    virtual ~BuildingGun() {}
    virtual void buildStock() = 0;
    virtual void buildMuzzle() = 0;
    virtual void buildMagazine() = 0;
    virtual void buildForeGrip() = 0;
    virtual void buildSight() = 0;
    virtual unique_ptr<Gun> GunsDetails() = 0;
};

// Concrete Class 
class HandGun : public BuildingGun {
private:
    unique_ptr<Gun> gun;
public:
    HandGun() {
        gun = make_unique<Gun>();
    }
    void buildStock() { gun->setStock("No Stock for HandGun"); }
    void buildMuzzle() { gun->setMuzzle("Silencer"); }
    void buildMagazine() { gun->setNoOfBullets(15); }
    void buildForeGrip() { gun->setForeGrip(false); }
    void buildSight() { gun->setSight("Red Dot"); }
    unique_ptr<Gun> GunsDetails() { return move(gun); }
};

class AssaultRifle : public BuildingGun{
    private:
        unique_ptr<Gun> gun;
    public:
        AssaultRifle(){
            gun = make_unique<Gun>();
        }

        void buildStock() { gun->setStock("Metal Stock"); }
        void buildMuzzle() { gun->setMuzzle("Compersor"); }
        void buildMagazine() { gun->setNoOfBullets(40); }
        void buildForeGrip() { gun->setForeGrip(true); }
        void buildSight() { gun->setSight("3x Scope"); }
        unique_ptr<Gun> GunsDetails() { return move(gun); }
};

// Director Class
class BuilderDirector {
public:
    unique_ptr<Gun> ConstructGun(unique_ptr<BuildingGun> hg) {
        hg->buildStock();
        hg->buildMuzzle();
        hg->buildMagazine();
        hg->buildForeGrip();
        hg->buildSight();
        return hg->GunsDetails();
    }

    unique_ptr<Gun> ConstructAssaultGun(unique_ptr<BuildingGun> ag){
        ag->buildStock();
        ag->buildMuzzle();
        ag->buildMagazine();
        ag->buildForeGrip();
        ag->buildSight();
        return ag->GunsDetails();
    }
};

int main()
{
    BuilderDirector director;

    // Constructing a Hand Gun;
    unique_ptr<HandGun> hg = make_unique<HandGun>();
    unique_ptr<Gun> handgun = director.ConstructGun(move(hg));
    handgun->previewGun();

    cout<<endl;
    //constructing a Assault Rifle;
    unique_ptr<AssaultRifle> ag = make_unique<AssaultRifle>();
    unique_ptr<Gun> assaultRifle = director.ConstructAssaultGun(move(ag));
    assaultRifle->previewGun();


    return 0;
}
