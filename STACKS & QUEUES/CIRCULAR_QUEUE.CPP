#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:
    int* arr;
    int size;
    int front;
    int rear;

    // Constructor to initialize the queue
    CircularQueue(int n) {
        this->size = n;
        this->arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    // Enqueue operation
    bool enqueue(int value) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            return false;
        }

        // If queue is initially empty
        else if (front == -1) {
            front = 0;
            rear = 0;
            arr[rear] = value;
        }

        // If rear is at the end and front is not at 0, wrap around
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        }

        // Normal case: just move rear forward
        else {
            rear++;
            arr[rear] = value;
        }

        return true;
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1) {
            return -1; // Queue is empty
        }

        int ans = arr[front];
        arr[front] = -1; // Optional: clear the slot

        // Only one element was in queue
        if (front == rear) {
            front = -1;
            rear = -1;
        }

        // Wrap front to beginning if it's at the end
        else if (front == size - 1) {
            front = 0;
        }

        // Move front forward normally
        else {
            front++;
        }

        return ans;
    }
};

// Main function to test CircularQueue
int main() {
    CircularQueue q(5); // Queue with size 5

    // Enqueue some values
    cout << "Enqueue 10: " << q.enqueue(10) << endl;
    cout << "Enqueue 20: " << q.enqueue(20) << endl;
    cout << "Enqueue 30: " << q.enqueue(30) << endl;
    cout << "Enqueue 40: " << q.enqueue(40) << endl;
    cout << "Enqueue 50: " << q.enqueue(50) << endl; // Should be false (queue full)

    // Dequeue and print
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    // Enqueue after wrap-around
    cout << "Enqueue 60: " << q.enqueue(60) << endl;
    cout << "Enqueue 70: " << q.enqueue(70) << endl;

    // Dequeue remaining
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl; // Should be -1 (empty)

    return 0;
}
