#include <bits/stdc++.h>
using namespace std;

// Recursive function to reverse the queue
void reverse(queue<int> &q) {
    // Base condition: If the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Get the front element and remove it
    int front = q.front();
    q.pop();

    // Recursively reverse the remaining queue
    reverse(q);

    // Push the front element to the back of the queue
    q.push(front);
}

// Function to reverse a queue using recursion
queue<int> reverseQueue(queue<int> q) {
    reverse(q);
    return q;
}

// Function to reverse a queue using a stack
queue<int> reverseQueueUsingStack(queue<int> q) {
    stack<int> s;

    // Push all elements of the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Push all elements back to the queue from the stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Reverse using recursion
    queue<int> reversed1 = reverseQueue(q);
    cout << "Reversed using recursion: ";
    while (!reversed1.empty()) {
        cout << reversed1.front() << " ";
        reversed1.pop();
    }
    cout << endl;

    // Reverse using stack
    queue<int> reversed2 = reverseQueueUsingStack(q);
    cout << "Reversed using stack: ";
    while (!reversed2.empty()) {
        cout << reversed2.front() << " ";
        reversed2.pop();
    }
    cout << endl;

    return 0;
}
