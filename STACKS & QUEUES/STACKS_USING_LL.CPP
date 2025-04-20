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
    int size;
    Node* top;

    Stack(){
        this->size = 0 ;
        this->top = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop(){
        if(top!=NULL){
            Node* temp = top;
            top = temp->next;
            delete temp;
            size--;
        }
        
        
    }

    int peek(){
        if(top!=NULL){
            return top->data;
        }  
    }

    int getSize() {
        return size;
    }

    void display(){
        Node* temp = top;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp->next;
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

    cout << "Stack size: " << st.getSize() << endl;

    return 0;
    return 0;
}   