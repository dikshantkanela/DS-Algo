#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    int height;
    int weight;
    void speak(){
        cout<<"I speak";
    }
};

class Dog: public Animal{
    public:
    void speak(){
        cout<<"I bark";
    }
};


int main(){  
    Animal animal_obj;
    Dog Sam;
    Sam.speak(); // I bark
    return 0;
}