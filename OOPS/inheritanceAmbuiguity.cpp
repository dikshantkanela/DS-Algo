#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    void fn(){
        cout<<"I am A";
    }
};

class B{
    public:
    void fn(){
        cout<<"I am B";
    }
};

class C: public A, public B{
    
};

int main(){
    C comrade;
    // Scope Resolution Operator (::)
    comrade.B::fn();
    comrade.A::fn();
    return 0;
}