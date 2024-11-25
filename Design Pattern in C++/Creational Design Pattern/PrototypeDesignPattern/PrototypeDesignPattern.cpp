#include<iostream>
#include<algorithm>
#include<memory>

using namespace std;

class Cell{
    public:
        virtual ~Cell(){

        }

        virtual unique_ptr<Cell> clone() = 0;
        virtual void showCellInfo() = 0;
};

class SkinCell : public Cell{
    private:
        string cell;
    public:
        SkinCell(string cell){
            this->cell = cell;
        }

        unique_ptr<Cell> clone(){
            return make_unique<SkinCell>(*this);
        }

        void showCellInfo(){
            cout<<"This is the Skin Cell "<<cell<<endl;
        }

};

class BloodCell : public Cell{
    private:   
        string cell;
    public:
        BloodCell(string cell){
            this->cell = cell;
        }

        unique_ptr<Cell> clone(){
            return make_unique<BloodCell>(*this);
        }

        void showCellInfo(){
            cout<<"This is the Blood Cell "<<cell<<endl;
        }
};

int main()
{
    unique_ptr<Cell> ce = make_unique<SkinCell>("melanocytes");
    ce->showCellInfo();

    unique_ptr<Cell> clonedSkinCell = ce->clone();
    clonedSkinCell->showCellInfo();

    unique_ptr<Cell> ce2 = make_unique<BloodCell>("Platlets");
    ce2->showCellInfo();

    unique_ptr<Cell> clonedBloodCell = ce2->clone();
    clonedBloodCell->showCellInfo();

    unique_ptr<Cell> UltimateClone = clonedSkinCell->clone();
    UltimateClone->showCellInfo();

    return 0;
}