#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    Queue(int size = 100){ //setting default if no arguement passed
        this->size = size;
        this->arr = new int [size];
        this->front = 0; // index of front in arr
        this->rear = 0; // index of rear in arr
    }

    void enqueue(int data){
        if(rear>=size){
           cout<<"Queue is Full";
        }

        else{
           arr[rear] = data;
           rear++; 
        }

    }

    void dequeue(){
        // check if queue is empty : 
        if(rear == front){
            cout<< "Queue is empty!";
        }

        else{
            front++;
        }

    }

    
    bool isEmpty() {
        if(front == rear){
            return 1;
        }
        else{
            return 0;
        }
    }

    int front() {
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }



};


int main(){
    Queue q;

    return 0;
}