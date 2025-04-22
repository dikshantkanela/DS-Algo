#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;     // Use standard namespace to avoid prefixing std::

class Queue {
public:
    int* arr;     // Pointer to dynamically allocate array for queue
    int size;     // Maximum capacity of the queue
    int qfront;   // Index pointing to the front of the queue
    int rear;     // Index pointing to the rear (next insertion position)

    // Constructor to initialize the queue with size 1000
    Queue() {
        this->size = 1000;         // Set default queue size
        this->arr = new int[size]; // Allocate array dynamically
        this->qfront = 0;          // Initialize front index to 0
        this->rear = 0;            // Initialize rear index to 0
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        if (qfront == rear) { // If front and rear are equal, queue is empty
            return 1;         // Return true (empty)
        } else {
            return 0;         // Return false (not empty)
        }
    }

    // Function to insert an element at the rear of the queue
    void enqueue(int data) {
        if (!(rear >= size)) {     // Check if there is space in the queue
            arr[rear] = data;      // Store data at rear index
            rear++;                // Move rear to the next position
        }
        // If rear >= size, we don't insert (overflow condition silently ignored here)
    }

    // Function to remove and return the front element from the queue
    int dequeue() {
        if (rear == qfront) {      // Check if queue is empty
            return -1;             // Return -1 if there is nothing to dequeue
        } else {
            int ans = arr[qfront]; // Store the front element to return
            arr[qfront] = -1;      // Optional: mark dequeued slot with -1
            qfront++;              // Move front to the next element

            // Reset the queue if all elements are removed
            if (qfront == rear) {
                qfront = 0;        // Reset front to 0
                rear = 0;          // Reset rear to 0
            }

            return ans;            // Return the dequeued value
        }
    }

    // Function to return the front element without removing it
    int front() {
        if (qfront == rear) {      // Check if queue is empty
            return -1;             // Return -1 if no front element
        } else {
            return arr[qfront];    // Return the front element
        }
    }
};



int main(){
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Enqueued 10, 20, 30" << endl;

    // Show front element
    cout << "Front element: " << q.front() << endl;  // Should be 10

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl;     // Should remove 10
    cout << "Front element after dequeue: " << q.front() << endl; // Should be 20

    // Dequeue all to make it empty
    q.dequeue(); // removes 20
    q.dequeue(); // removes 30

    // Try to dequeue from empty queue
    cout << "Dequeued from empty queue: " << q.dequeue() << endl; // Should be -1

    // Check if queue is empty
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}