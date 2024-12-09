#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;


class EuropeanSocket {
    public:
        virtual ~EuropeanSocket(){

        }

        virtual void plugInEuropeanSocket() = 0;
};

class USAPlug {
    public:
        void plugInUsaSocket(){
            cout<<"USA Plug Plugged in USA Socket "<<endl;
        }
};

class PlugAdapter : public EuropeanSocket{
    private:
        unique_ptr<USAPlug> us;
    public:
        PlugAdapter(unique_ptr<USAPlug> us){
            us = make_unique<USAPlug>();
        }
    
    void plugInEuropeanSocket(){
        cout<<"Using adapter to connect USA plug to EUROPEAN socket "<<endl;
        us->plugInUsaSocket();
    }
};

int main()
{
    unique_ptr<USAPlug> us = make_unique<USAPlug>();   
    
    unique_ptr<EuropeanSocket> adapter = make_unique<PlugAdapter>(us);
    adapter->plugInEuropeanSocket();
    return 0;
}