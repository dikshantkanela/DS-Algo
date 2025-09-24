#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* next;
    
       Node(int data){
           this->data = data;
           this->next = NULL;
       }
};

class Stack{
    public:
       Node* top;
       int size;

       Stack(){
          this->size = 0; // very imp
          this->top = NULL; // very imp

       }
        
       void push(int data){
          Node* newNode = new Node(data);
          newNode->next = top;
          top = newNode;
          size++;
       }

       void pop(){
          if(size == 0){
            cout<<"Stack is empty!";

          }

          else{
          Node* nodeToDelete = top;
          top = nodeToDelete->next;
          delete nodeToDelete;
          size--;

          }
         
       }

       int peek(){
        if(size == 0){
            cout<<"Stack is empty!";
            return -1;
        }
        else{
           return this->top->data;
        }

       }

       int getSize(){
        return size;

       }

       void display(){
          if(size == 0){
             cout<<"Nothing to display!";
          }
          else{
             Node* temp = top;
             while(temp!=NULL){
                cout<<temp->data;
                temp = temp->next;
             }
          
          } 

       }
};

int main(){
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display(); // Stack top -> 30 20 10 <- bottom

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "After popping:\n";
    st.display();
    cout<<endl;

    cout << "Stack size: " << st.getSize() << endl;
    st.pop();
    st.pop();
    st.display();
    return 0;
    return 0;
}   