#include <bits/stdc++.h> 
using namespace std;

// Inserts an element into a sorted stack such that the stack remains sorted (ascending order)
void insertSorted(stack<int> &stack, int x){
    if(stack.empty() || x >= stack.top()){ 
        // if the top of the stack is lower than or equal to the current x then simply push x
        stack.push(x);
        return;
    }

    // otherwise pop the top and recur until correct position is found
    int top = stack.top();
    stack.pop();
    insertSorted(stack, x);
    
    // push the popped element back ONCE X IS CORRECTLY INSERTED
    stack.push(top);	
}

// Recursively sorts the stack in ascending order
void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int element = stack.top();
    stack.pop(); // remove the top element
    sortStack(stack); // recursively sort the remaining stack
    insertSorted(stack, element); // insert the element back in sorted order
}

int main(){
    stack<int> s;

    // pushing some values into the stack
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    // function to sort the stack
    sortStack(s);

    // printing the sorted stack
    cout << "Sorted stack (top to bottom): ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
