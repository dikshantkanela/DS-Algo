#include <bits/stdc++.h>
using namespace std;

// ----------- METHOD 1: Using 1 Extra Queue -----------
void interLeaveQueueOneQueue(queue<int> &q) {
    queue<int> q1;
    int mid = q.size() / 2;

    for (int i = 0; i < mid; i++) {
        int front = q.front();
        q.pop();
        q1.push(front);
    }

    while (!q1.empty()) {
        int front = q1.front();
        q1.pop();
        q.push(front);

        int mainFront = q.front();
        q.pop();
        q.push(mainFront);
    }
}

// ----------- METHOD 2: Using 2 Extra Queues -----------
void interLeaveQueueTwoQueues(queue<int> &q) {
    queue<int> q1;
    queue<int> q2;
    int mid = q.size() / 2;
    int count = 0;

    while (!q.empty()) {
        while (count < mid) {
            int front = q.front();
            q.pop();
            q1.push(front);
            count++;
        }
        int front = q.front();
        q.pop();
        q2.push(front);
    }

    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int front1 = q1.front();
            q1.pop();
            q.push(front1);
        }
        if (!q2.empty()) {
            int front2 = q2.front();
            q2.pop();
            q.push(front2);
        }
    }
}

// ----------- METHOD 3: Using Stack -----------
void interLeaveQueueUsingStack(queue<int> &q) {
    stack<int> st;
    int mid = q.size() / 2;

    // Step 1: Push first half elements into stack
    for (int i = 0; i < mid; i++) {
        int front = q.front();
        q.pop();
        st.push(front);
    }

    // Step 2: Enqueue back elements from stack
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        q.push(top);
    }

    // Step 3: Move first half elements to the back of the queue
    for (int i = 0; i < mid; i++) {
        int front = q.front();
        q.pop();
        q.push(front);
    }

    // Step 4: Again push first half into stack
    for (int i = 0; i < mid; i++) {
        int front = q.front();
        q.pop();
        st.push(front);
    }

    // Step 5: Interleave stack and queue elements
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        q.push(top);

        int front = q.front();
        q.pop();
        q.push(front);
    }
}

int main() {
    queue<int> q;

    // Example Input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // --------- CALL ONE FUNCTION AT A TIME ---------

    // Method 1: Using 1 Queue
    // interLeaveQueueOneQueue(q);

    // Method 2: Using 2 Queues
    // interLeaveQueueTwoQueues(q);

    // Method 3: Using Stack
    interLeaveQueueUsingStack(q);

    // Output
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
