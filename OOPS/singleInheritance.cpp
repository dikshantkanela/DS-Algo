#include<bits/stdc++.h>
using namespace std;


class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"Speaking!";
    }
};

class Dog: public Animal{

};



int main(){
    Dog sam;
    sam.speak();
    return 0;
}