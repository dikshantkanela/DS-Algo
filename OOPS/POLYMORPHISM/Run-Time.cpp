#include <iostream>
using namespace std;

 class Animal {
public:
    int height;
    int weight;

    virtual void speak() {  // 🔑 Virtual function
        cout << "I speak" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  // 🔁 Overriding the base class function
        cout << "I bark" << endl;
    }
};

int main() {
    Animal animal_obj;
    Dog sam;

    // Direct object calls
    sam.speak();          // Output: I bark
    animal_obj.speak();   // Output: I speak

    // 🔁 Runtime polymorphism using base class pointer
    Animal* ptr;

    ptr = &sam;  // Pointing to derived class object
    ptr->speak(); // Output: I bark (runtime dispatch via virtual)

    Animal* a = new Dog();
    a->speak(); // Output: Dog barks ✅


    return 0;
}
