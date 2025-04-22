#include <bits/stdc++.h>
using namespace std;

// ------------------ Recursive Approach ------------------
void solveRecursive(stack<int>& inputStack, int count, int mid) {
    if (count == mid) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top(); // store for future 
    inputStack.pop(); // remove for current 

    solveRecursive(inputStack, count + 1, mid);

    inputStack.push(num); // push the stored for future ones back
}

void deleteMiddleRecursive(stack<int>& inputStack, int N) {
    int mid = (N % 2 == 0) ? (N / 2 - 1) : (N / 2);
    solveRecursive(inputStack, 0, mid);
}

// ------------------ Iterative Approach (Old) ------------------
void deleteMiddleIterative(stack<int>& inputStack, int N) {
    int mid = N / 2;
    vector<int> temp;

    // Pop all elements into vector
    while (!inputStack.empty()) {
        temp.push_back(inputStack.top());
        inputStack.pop();
    }

    // Push elements back into stack, skipping the middle
    for (int i = temp.size() - 1; i >= 0; i--) {
        if (i != mid) {
            inputStack.push(temp[i]);
        }
    }
}

// ------------------ Main Function to Test Both ------------------
int main() {
    stack<int> s1;
    for (int i = 1; i <= 5; i++) {
        s1.push(i); // Stack: 1(bottom) → 5(top)
    }

    stack<int> s2 = s1; // Duplicate for second method

    cout << "Original Stack: ";
    stack<int> temp = s1;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n\n";

    // Test Recursive Method
    deleteMiddleRecursive(s1, s1.size());
    cout << "After Recursive Delete: ";
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << "\n";

    // Test Iterative Method
    deleteMiddleIterative(s2, s2.size());
    cout << "After Iterative Delete: ";
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}
