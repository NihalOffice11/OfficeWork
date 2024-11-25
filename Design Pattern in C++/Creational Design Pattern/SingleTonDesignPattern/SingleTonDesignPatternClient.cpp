#include<iostream>
#include<algorithm>
#include "SingleTonDesignPattern.h"
using namespace std;


int main()
{
    string str ;
    cout<<"Enter the Government who won the Elections : ";
    cin>>str;
    Government* gov = Government :: getInstance(str);
    gov->selectedGovernment();

    Government* gov1 = Government :: getInstance("INC");
    gov1->selectedGovernment();

    Government* gov2 = Government :: getInstance("BJP");
    gov2->selectedGovernment();

    Government* gov3 = Government :: getInstance("BSP");
    gov3->selectedGovernment();

    Government* gov4 = Government :: getInstance("AAP");
    gov4->selectedGovernment();

    cout<<Government::count<<endl;

    if(gov == gov1){
        cout<<"Both the Governments are same"<<endl;
    }
    else{
        cout<<"Both the Governments are different"<<endl;
    }

}



