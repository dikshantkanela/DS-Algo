#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    char* model;
    int modelYear;

    // DEFAULT CONSTRUCTOR
    Car() {
        cout << "DEFAULT CONSTRUCTOR!" << endl;
        // model = nullptr;
        // modelYear = 0;
    }

    // PARAMETERIZED CONSTRUCTOR (Deep Copy)
    Car(const char* model, int my) {
        this->model = new char[strlen(model) + 1]; // Allocate dynamic memory
        strcpy(this->model, model); // Copy the string

        this->modelYear = my;
    }

    // COPY CONSTRUCTOR (Deep Copy)
    Car(const Car &myCar) {
        cout << "COPY CONSTRUCTOR (Deep Copy) called!" << endl;
        this->model = new char[strlen(myCar.model) + 1]; // Allocate new memory
        strcpy(model, myCar.model); // Copy content
        
        this->modelYear = myCar.modelYear;
    }

    // // DESTRUCTOR (To Free Allocated Memory)
    // ~Car() {
    //     cout << "Destructor called for model: " << model << endl;
    //     delete[] model; // Free allocated memory
    // }

    // Function to safely update model
    void setModel(const char* newModel) {
        delete[] model; // Free old memory
        model = new char[strlen(newModel) + 1]; // Allocate new memory
        strcpy(model, newModel); // Copy new string
    }
};

int main() {
    Car myCar; // Default constructor

    Car Virtus("Virtus", 2024); // Deep Copy Constructor

    cout << "Original Car Model: " << Virtus.model << endl;
    cout << "Original Car Model Year: " << Virtus.modelYear << endl;

    // Creating a copy using Copy Constructor
    Car Slavia(Virtus);

    cout << "Copied Car Model: " << Slavia.model << endl;
    cout << "Copied Car Model Year: " << Slavia.modelYear << endl;

    // Changing Slavia's model safely
    Slavia.setModel("Slavia");

    cout << "Updated Slavia Model: " << Slavia.model << endl;
    cout << "Virtus Model (Should remain unchanged): " << Virtus.model << endl;

    return 0;
}
