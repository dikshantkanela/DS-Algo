#include<bits/stdc++.h>
using namespace std;

// INTERFACE ONLY HAS VIRTUAL FUNCTIONS AND DO NOT HAVE ANY DATA MEMBERS OR OTHER FUNCTIONS
// INTERFACES DO NOT HAVE ANY SORT OF FUNCTIONALITY SINCE THEY DONT HAVE OTHER FUNCTIONS
class Animal{
    public:
    virtual void speak() = 0;
    virtual void walk() = 0;

};

class Dog : public Animal{
    public:
     void speak() override{
        cout<<"WOOF WOOF";
    }

    void walk() override{
        cout<<"1 STEP FURTHER!";
    }


};


int main(){
    // Animal hey;
    Dog hey;
    hey.speak();

    return 0;
}