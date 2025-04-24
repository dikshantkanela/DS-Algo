#include <iostream>
#include <stack>
using namespace std;

// Class to implement queue using two stacks
class MyQueue {
public:
    stack<int> input;  // Stack to push new elements
    stack<int> output; // Stack to pop/peek elements in FIFO order

    // Constructor
    MyQueue() {}

    // Push element to the back of the queue
    void push(int x) {
        input.push(x); // Simply push to input stack
    }

    // Removes the element from front of queue and returns it
    int pop() {
        int ans = -1;

        // If both stacks are empty, the queue is empty
        if (input.empty() && output.empty()) {
            return -1;
        } 
        // Transfer elements from input to output if output is empty
        else if (output.empty()) {
            while (!input.empty()) {
                int top = input.top();
                input.pop();
                output.push(top); // Reverses the order for correct queue behavior
            }
            ans = output.top();
            output.pop();
        }
        // If output is not empty, just pop from it
        else {
            ans = output.top();
            output.pop();
        }
        return ans;
    }

    // Get the front element
    int peek() {
        int ans = -1;

        if (input.empty() && output.empty()) {
            return -1; // Queue is empty
        } 
        else if (output.empty()) {
            // Transfer all elements to output for correct order
            while (!input.empty()) {
                int top = input.top();
                input.pop();
                output.push(top);
            }
            ans = output.top();
        } 
        else {
            ans = output.top();
        }
        return ans;
    }

    // Check whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;

    // Test push
    q.push(10);
    q.push(20);
    q.push(30);

    // Test peek
    cout << "Front element: " << q.peek() << endl; // Output: 10

    // Test pop
    cout << "Popped: " << q.pop() << endl; // Output: 10

    // Test peek again
    cout << "Front element after pop: " << q.peek() << endl; // Output: 20

    // Test empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No

    // Pop all elements
    q.pop(); // 20
    q.pop(); // 30

    cout << "Is queue empty after popping all? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}