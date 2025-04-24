#include <bits/stdc++.h> 
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Constructor to initialize the deque with a given size
    Deque(int n)
    {
        this->size = n;             // Set the size of the deque
        this->arr = new int[size];  // Allocate memory for the array
        this->front = -1;           // Initialize front index
        this->rear = -1;            // Initialize rear index
    }

    // Insert an element at the front of the deque
    bool pushFront(int x)
    {
        // Check if deque is full
        if(front == 0 && rear == size-1 || front == (rear+1)%size){
            return false;
        }

        // If deque is initially empty
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[front] = x;
        }

        // If front is at first index and space is available at end
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = x;
        }

        // Normal case: just decrement front
        else{
            front--;
            arr[front] = x;
        }
        return true;
    }

    // Insert an element at the rear of the deque
    bool pushRear(int x)
    {
        // Check if deque is full
        if(front == 0 && rear == size-1 || front == (rear+1)%size){
            return false;
        }

        // If deque is empty
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = x;
        }

        // Wrap rear around if it's at the end
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = x;
        }

        // Normal case: increment rear
        else{
            rear++;
            arr[rear] = x;
        }
        return true;
    }

    // Remove and return element from the front
    int popFront()
    {
        if(front == -1){
            return -1; // Deque is empty
        }

        int ans = arr[front];
        arr[front] = -1;

        // Only one element was present
        if(front == rear){
            front = -1;
            rear = -1;
        }

        // Wrap front around if needed
        else if(front == size-1){
            front = 0;
        }

        // Move front forward normally
        else{
            front++;
        }
        return ans;
    }

    // Remove and return element from the rear
    int popRear()
    {
        if(front == -1){
            return -1; // Deque is empty
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // Only one element was present
        if(front == rear){
            front = -1;
            rear = -1;
        }

        // Wrap rear around if needed
        else if(rear == 0){
            rear = size-1;
        }

        // Move rear backward normally
        else{
            rear-- ;
        }
        return ans;
    }

    // Return front element of deque
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Return rear element of deque
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Check if deque is full
    bool isFull()
    {
        return (front == 0 && rear == size-1) || (front == (rear+1)%size);
    }
};

// ----------- Visual Studio Code style main function -----------
int main() {
    // Create a deque of size 5
    Deque dq(5);

    // Push elements from both ends
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(3);

    // Get front and rear
    cout << "Front: " << dq.getFront() << endl;  // Should be 3
    cout << "Rear: " << dq.getRear() << endl;    // Should be 20

    // Pop elements
    dq.popFront();  // Pops 3
    dq.popRear();   // Pops 20

    // Get front and rear again
    cout << "Front after popping: " << dq.getFront() << endl;  // Should be 5
    cout << "Rear after popping: " << dq.getRear() << endl;    // Should be 10

    return 0;
}
