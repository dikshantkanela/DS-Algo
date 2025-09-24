#include <bits/stdc++.h> 
using namespace std;

// Inserts an element into a sorted stack such that the stack remains sorted (ascending order)
void insertSorted(stack<int> &stack, int x){
    if(stack.empty() || x>=stack.top()){
        stack.push(x);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertSorted(stack,x);
    stack.push(top);
   
}

// Recursively sorts the stack in ascending order
void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int top = stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack,top);

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
