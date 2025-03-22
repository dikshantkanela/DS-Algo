#include<bits/stdc++.h>
using namespace std;
//ABSTRACT CLASS : HAS ATLEAST ONE VIRTUAL FUNCTION = 0
//A virtual function in C++ is a member function of a base class that is overridden in a derived class.

class Animal{
    public:
    virtual void speak() = 0; // WE ARE JUST PROVIDING THE PROTOTYPE AND HIDING THE IMPLEMENTATION OF THIS FUNC
    int height;
    int weight;
    void showMessage(){
    cout << "Animals make sounds!" << endl;
    }
};

class Dog: public Animal{
    public:
    void speak() override {
        cout<<"WOOF WOOF";
    }
};

int main(){
    // Animal a; // OBJECTS OF VIRTUAL CLASS NOT POSSIBLE
    Dog sam;
    sam.speak();
    return 0;
}