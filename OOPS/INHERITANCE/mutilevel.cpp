#include <bits/stdc++.h>
using namespace std;

// Base Class (Animal)
class Animal {
public:
    string species;
    int age;

    Animal(string species, int age) { // Constructor
        this->species = species;
        this->age = age;
    }

    void eat() {
        cout << species << " is eating!" << endl;
    }
};

// Derived Class (Dog) from Animal
class Dog : public Animal {
public:
    string breed;
    bool isTrained;

    Dog(string species, int age, string breed, bool isTrained) 
        : Animal(species, age) { // Call Base Class Constructor
        this->breed = breed;
        this->isTrained = isTrained;
    }

    void bark() {
        cout << breed << " is barking!" << endl;
    }
};

// Further Derived Class (GoldenRetriever) from Dog
class GoldenRetriever : public Dog {
public:
    string furColor;
    bool isFriendly;

    GoldenRetriever(string species, int age, string breed, bool isTrained, string furColor, bool isFriendly) 
        : Dog(species, age, breed, isTrained) { // Call Dog Constructor
        this->furColor = furColor;
        this->isFriendly = isFriendly;
    }

    void fetch() {
        cout << breed << " with " << furColor << " fur is fetching the ball!" << endl;
    }
};

int main() {
    // Creating an object of GoldenRetriever
    GoldenRetriever gr("Mammal", 3, "Golden Retriever", true, "Golden", true);

    // Accessing methods and properties from all levels
    cout << "Species: " << gr.species << ", Age: " << gr.age << endl;
    cout << "Breed: " << gr.breed << ", Trained: " << (gr.isTrained ? "Yes" : "No") << endl;
    cout << "Fur Color: " << gr.furColor << ", Friendly: " << (gr.isFriendly ? "Yes" : "No") << endl;

    gr.eat();   // Inherited from Animal
    gr.bark();  // Inherited from Dog
    gr.fetch(); // Defined in GoldenRetriever

    return 0;
}
