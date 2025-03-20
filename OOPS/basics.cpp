#include<bits/stdc++.h>
using namespace std;

class Hero{

    private: // inaccecible outside the class
    char level;
 
    public:
    int health;
    // CONSTRUCTOR : 
    Hero(){
        cout<<"Constructor Called!";
    }
    // PARAMETERISED CONSTRUCTOR : 
    Hero(int health, char level){
        this->health = health;
        this->level = level;
        cout<<"this->"<<this<<endl; // this stores the address of the object that is instantiated
    }

    //COPY CONSTRUCTOR : 
    Hero(Hero &source){
        cout<<"Copy constructor called"<<endl;
        this->health = source.health;
        this->level = source.level;
    }

    //GETTERS AND SETTERS : 
    int getHealth(){
        return health;  
    }

    char getLevel(){
        return level;
    }
    
    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }

};

int main(){
    Hero dikshant; // making an OBJECT which is an INSTANCE OF CLASS

    dikshant.health = 100;
    dikshant.setHealth(101);
    cout<<"Dikshant's Health = "<< dikshant.getHealth()<<endl;
    
    // dikshant.level = 'A'; //inaccecible
    dikshant.setLevel('A');
    cout<<"Dikshant's Level :"<< dikshant.getLevel()<<endl;
    cout<<"size of object : "<<sizeof(dikshant)<<endl;

    // static allocation : 
    Hero a;
    a.setHealth(90);
    a.setLevel('B');
    cout<<"Level of hero a : " <<a.getLevel()<<endl; 
    cout<<"Health of hero a : " <<a.getHealth()<<endl; 
    // dynamic allocation : 
    Hero* b = new Hero;
    b->setHealth(100);
    b->setLevel('S');
    cout<<"Level of hero b : " <<b->getLevel()<<endl; 
    cout<<"Health of hero b : " <<b->getHealth(); 
    

    // INSTANTATING OBJECT USING PARAMETERISED CONSTRUCTOR : 
    
    Hero shaktiman(99,'Z');  // Instead of Hero shaktiman = Hero(99,'Z');
    cout<<"Level of hero shaktiman : " <<shaktiman.getLevel()<<endl; 
    cout<<"Health of hero shaktiman : " <<shaktiman.getHealth()<<endl; 
    cout<<"Address of shaktiman obj : "<< &shaktiman<<endl;

    // COPY CONSTRUCTOR : The copy constructor is a special constructor that creates a new object as a copy of an existing object
    Hero S(50,'A');
    Hero R(S); // R is a copy of S



    return 0;
}