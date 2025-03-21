#include<bits/stdc++.h>
using namespace std;

class Battery{
    public:
    int rating;
    Battery(){
        cout<<"c1";
    }
    
};

class Car{
    public:
    string name;
    int horsepower;
    Car(){
        cout<<"c2";
    }

};

class ElectricCar: public Battery, public Car{
    public:
    int yearsWarranty;
    void rev(){
        cout<<"Electric cars cannot rev xD";
    }

    ElectricCar(){
        cout<<"c3";
    }

};

int main(){
    ElectricCar CretaEv;
    CretaEv.rev();
    return 0;
}