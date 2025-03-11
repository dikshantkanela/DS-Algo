#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void print(Node* &head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<< " -> ";
        temp = temp->next; // move to the next node
    }
    cout<< " NULL ";
}

void insertAtHead(Node* &head, int data){
   Node* temp = head;
   temp->data = data;
   head = temp;
}

int main(){
    // Creating nodes
    Node* node1 = new Node(5);
    Node* node2 = new Node(10);

    // Linking nodes
    node1->next = node2; // Connect node1 to node2

    // Head of the list
    Node* head = node1;

    // Printing the linked list
    print(head);  // 5 -> 10 ->  NULL 
    cout<<endl;

    // Inserting at head
    insertAtHead(head,25);
    print(head);// 25 -> 5 -> 10 ->  NULL
    return 0;
}