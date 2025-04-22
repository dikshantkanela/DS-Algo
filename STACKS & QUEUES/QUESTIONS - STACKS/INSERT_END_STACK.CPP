#include <bits/stdc++.h>
using namespace std;

// ****
// main intent of algo is to empty the entire stack and when it is emptied fill it with the x at the bottom and then backtract with older elements to rebuild!
void solve(stack<int>& myStack, int x){
    // base case :
    if(myStack.empty()){
        myStack.push(x); // pushes the x at bottom
        return ;
    }

    int top = myStack.top();
    myStack.pop(); // removes elements of stacks one by one in each call
    solve(myStack,x);
    myStack.push(top);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x); // recursive func
    return myStack;
}

// function to print elements of stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int x = 0;

    cout << "Original Stack (Top to Bottom): ";
    printStack(st);

    stack<int> result = pushAtBottom(st, x);

    cout << "After pushing " << x << " at the bottom: ";
    printStack(result);

    return 0;
}
