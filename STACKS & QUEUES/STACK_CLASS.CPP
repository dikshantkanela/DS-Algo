#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    // data members : 
    int* arr;
    int size;
    int top;
        Stack(int size){
            this->size = size;
            this->arr = new int[size];
            this->top = -1;
        }
    // methods : 

    void push(int data){
        if(top>=size-1){
            cout<<"Stack is full!";
        }
        else{
            top++;
            arr[top] = data;
        }

    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty!";
        }

        else{
            top--;
        }

    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[top];
        }

    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }

    }

    int getSize(){
        return top+1;

    }

       
};

int main(){
    Stack st(4);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.push(5);

    cout<<"Top of stack : "<< st.peek()<<endl;
    cout<<"Popping two elements : "<<endl;
    st.pop();
    st.pop();

    cout<<"Topmost Element : "<<st.peek()<<endl;
    cout<<"Size of stack : "<< st.getSize()<<endl;
    cout<<"After removing all elements :"<<endl;
    st.pop();
    st.pop();
    st.pop(); // stack underflow
    
    return 0;
}