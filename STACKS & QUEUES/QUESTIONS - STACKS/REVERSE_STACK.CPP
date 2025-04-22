/*
APPROACH:
This solution reverses a stack recursively without using any additional data structures such as arrays or another stack.

The algorithm works in two parts:
1. reverseStack() - Empties the stack and then rebuilds it in reverse order:
   - Base case: If stack is empty, return
   - Otherwise: Remove top element, reverse remaining stack, then insert the removed element at bottom
   
2. insertAtBottom() - Helper function to insert an element at the bottom of stack:
   - Base case: If stack is empty, push the element
   - Otherwise: Remove top element, insert our target element at bottom of remaining stack, then push removed element back

Time Complexity: O(n²) - Each element gets removed and reinserted multiple times
Space Complexity: O(n) - Recursive call stack stores n elements during the recursion
*/

#include <iostream>
#include <stack>

using namespace std;

// Helper function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &stack, int ele) {
    // Base case: if stack is empty, insert the element
    if(stack.empty()) {
        stack.push(ele);
        return;
    }
    
    // Save the top element
    int top = stack.top();
    stack.pop();
    
    // Recursively insert the element at the bottom
    insertAtBottom(stack, ele);
    
    // Push back the saved element
    stack.push(top);
}

// Function to reverse a stack using recursion
void reverseStack(stack<int> &stack) {
    // Base case: if stack is empty, nothing to reverse
    if(stack.empty()) {
        return;
    }
    
    // Remove the top element
    int top = stack.top();
    stack.pop();
    
    // Reverse the remaining stack
    reverseStack(stack);
    
    // Insert the removed element at the bottom
    insertAtBottom(stack, top);
}

// Function to print all elements in the stack
void printStack(stack<int> s) {
    cout << "Stack: ";
    // Create a copy so we don't modify the original
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;
    
    // Push some elements onto the stack
    myStack.push(1); // Bottom
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5); // Top
    
    cout << "Original ";
    printStack(myStack);
    
    // Reverse the stack
    reverseStack(myStack);
    
    cout << "Reversed ";
    printStack(myStack);
    
    // Test with different stack
    stack<int> emptyStack;
    cout << "\nEmpty ";
    printStack(emptyStack);
    
    reverseStack(emptyStack);
    cout << "Reversed empty ";
    printStack(emptyStack);
    
    // Test with single element
    stack<int> singleStack;
    singleStack.push(42);
    
    cout << "\nSingle element ";
    printStack(singleStack);
    
    reverseStack(singleStack);
    cout << "Reversed single element ";
    printStack(singleStack);
    
    return 0;
}