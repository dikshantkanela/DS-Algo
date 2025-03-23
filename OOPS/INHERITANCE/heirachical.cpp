#include <bits/stdc++.h>
using namespace std;

// Base Class (Animal)
class Animal {
public:
    void eat() {
        cout << "Animal is eating!" << endl;
    }
};

// Derived Class 1 (Dog) inherits from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking!" << endl;
    }
};

// Derived Class 2 (Cat) inherits from Animal
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing!" << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    // Dog actions
    d.eat();  // Inherited from Animal
    d.bark(); // Specific to Dog

    // Cat actions
    c.eat();  // Inherited from Animal
    c.meow(); // Specific to Cat

    return 0;
}
