#include<bits/stdc++.h>
using namespace std;

class Stack{
   public:
   int *arr;
   int size;
   int top;

   Stack(int size){
    this->size = size;
    this->arr = new int[size];
    this->top = -1; // initially no element present so -1
    // top is same as 0 indexing of array
   }

   void push(int element){
    if(top>=size-1){
        cout<<"Stack Overflow";
    }
    else{
        top++; // lines cant be reordered!
        arr[top] = element;
    }
   }

   void pop(){
    if(top == -1){
        cout<<"Stack Underflow!";
    }

    else{
        top--;
    }
   }

   int peek(){
    if(top == -1){
        cout<<"Stack is empty!";
        return -1;
    }

    else{
        return arr[top];
    }
   }

   bool empty(){
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