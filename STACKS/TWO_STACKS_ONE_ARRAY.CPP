#include <iostream>
using namespace std;

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    // Constructor
    TwoStack(int s) {
        this->size = s;
        this->arr = new int[s];
        this->top1 = -1;
        this->top2 = s;
    }

    // Push in Stack 1
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack1 Overflow\n";
        }
    }

    // Push in Stack 2
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack2 Overflow\n";
        }
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 == -1) {
            return -1;
        } else {
            int val = arr[top1];
            top1--;
            return val;
        }
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 == size) {
            return -1;
        } else {
            int val = arr[top2];
            top2++;
            return val;
        }
    }

    // Destructor
    ~TwoStack() {
        delete[] arr;
    }
};

// Main function for testing
int main() {
    TwoStack ts(5);  // Stack with total size 5

    ts.push1(10);
    ts.push1(20);
    ts.push2(100);
    ts.push2(200);

    cout << "Popped from Stack 1: " << ts.pop1() << endl;  // 20
    cout << "Popped from Stack 2: " << ts.pop2() << endl;  // 200

    ts.push1(30);
    ts.push2(300);

    cout << "Popped from Stack 1: " << ts.pop1() << endl;  // 30
    cout << "Popped from Stack 2: " << ts.pop2() << endl;  // 300

    return 0;
}
