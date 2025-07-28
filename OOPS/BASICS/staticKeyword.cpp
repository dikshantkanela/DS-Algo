#include<bits/stdc++.h>
using namespace std;

class Car{
   public:
   static int totalCars; 

   Car(){
    totalCars++;
    // cout<<totalCars<<" cars created!"<<endl;
   }

   static int showCars(){ // static func that can only access static variables!
    return totalCars;
   }

};

int Car::totalCars = 0; // HOW TO INITIALISE STATIC VARIABLES

int main(){
    cout<<Car::totalCars; // 0

    Car Kylaq;
    Car Sonet;
    cout<<Car::totalCars; // 2
    cout<<Sonet.totalCars<<endl; // 2
    cout<<Kylaq.totalCars<<endl; // 2 still! because static variables belong to class not objects
    
    // UPDATE : 
    Sonet.totalCars = 3;
    cout<<Sonet.totalCars<<endl; //3
    cout<<Kylaq.totalCars<<endl;  //3
    cout<<Car::totalCars<<endl; // still 3
    
    // UPDATE : 
    Car::totalCars =4;

    // DISPLAY static vars : 
    cout<<Car::totalCars<<endl;

    // calling static functions : 
    cout<<"Dikshant has "<< Car::showCars()<< " cars";



    return 0;
}