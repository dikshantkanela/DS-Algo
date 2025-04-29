#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> input;
    queue<int> output;

    MyStack() {}

    void push(int x) { input.push(x); }

    int pop() {
        if (input.empty() && output.empty()) {
            return -1;
        }
        if (input.size() == 1) {
            int front = input.front();
            input.pop();
            return front;
        } else {
            while (input.size() > 1) {
                int front = input.front();
                input.pop();
                output.push(front);
            }
            int ans = input.front();
            input.pop();
            while (!output.empty()) {
                input.push(output.front());
                output.pop();
            }
            return ans;
        }
    }

    int top() {
        if (!input.empty()) {
            return input.back();
        } else {
            return -1;
        }
    }

    bool empty() { return input.empty() && output.empty(); }
};

int main() {
    MyStack* obj = new MyStack();
    
    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top element: " << obj->top() << endl;      // Should print 30
    cout << "Popped element: " << obj->pop() << endl;   // Should print 30
    cout << "Top element: " << obj->top() << endl;      // Should print 20
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Should print No

    delete obj;
    return 0;
}
