#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Push elements at the back
    dq.push_back(10);   // dq: 10
    dq.push_back(20);   // dq: 10 20

    // Push elements at the front
    dq.push_front(5);   // dq: 5 10 20
    dq.push_front(3);   // dq: 3 5 10 20

    // Print deque elements
    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    // Output: Deque elements: 3 5 10 20

    // Access front and back
    cout << "Front element: " << dq.front() << endl;
    // Output: Front element: 3

    cout << "Back element: " << dq.back() << endl;
    // Output: Back element: 20

    // Pop front and back
    dq.pop_front();  // Removes 3 → dq: 5 10 20
    dq.pop_back();   // Removes 20 → dq: 5 10

    // Print updated deque
    cout << "Updated deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    // Output: Updated deque: 5 10

    // Check if empty
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;
    // Output: Is empty? No

    return 0;
}
