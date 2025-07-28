#include<bits/stdc++.h>
using namespace std;
class Human{
    public:
    int height;
    int weight;
    int age;
    
    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }

};

class Male: private Human{
    public:
    string color;


    void sleep(){
       cout<<"Human Sleeping!";
    }

    int getHeight(){
        return this->height;
    }
    int getWeight(){
        return this->weight;
    }
    void setHeight(int h){
        this->height = h;
    }

};

int main(){

    Male m1;
    cout<< m1.getHeight();
    cout<<m1.color;


    /* 
    Male obj1;
    // obj1.age = 20;
    cout<<obj1.age<<endl;
    cout<<obj1.height<<endl;
    obj1.setWeight(57);
    cout<<obj1.weight<<endl;
    cout<<obj1.color<<endl;
    obj1.sleep();
    */
   

    return 0;
}