#include <bits/stdc++.h>
using namespace std;

class Math {
public:
    // Function Overloading: Same function name, different parameters
    
    int a;

    int add(int x, int y) {
        return x + y;
    }

    int add(int x, int y, int z) {
        return x + y + z;
    }

    double add(int x, double y, int z) {
        return x + y + z;  // Returns float value
    }

    // OPERATOR OVERLOADING : using + as -
    int operator + (Math &obj2){ // parameter is the second operand
       int val1 =  this->a; // this is the first operand
       int val2 = obj2.a; 
       return val1-val2;
    }
};

int main() {
    Math obj;
    
    cout << obj.add(1, 2) << endl;       // Calls add(int, int)
    cout << obj.add(1, 2, 3) << endl;    // Calls add(int, int, int)
    cout << obj.add(1, 3.5, 3) << endl;  // Calls add(int, float, int)
    
    Math obj1;
    Math obj2;
    obj1.a = 10;
    obj2.a = 5;
    cout<<obj1+obj2;
    return 0;
}
