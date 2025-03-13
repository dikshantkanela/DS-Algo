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
   Node* temp = new Node(data);
   temp->next = head; // head represents address 
   head = temp;

}

void insertAtTail(Node* &tail, int data){
   Node* temp = new Node(data);
   tail->next = temp;
   tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail ,int position, int data){
    if(position == 1){
        insertAtHead(head,data);
        return; // to ensure the function stops here
    }
    Node *temp = head;
    int count = 1;

    while(count<position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){ // that means we are inserting at tail!
        insertAtTail(tail,data);
        return;
     }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

int main(){
    // Creating nodes
    Node* node1 = new Node(5);
    Node* node2 = new Node(10);
    Node* node3 = new Node(11);

    // Linking nodes
    node1->next = node2; // Connect node1 to node2
    node2->next = node3;
    // Head of the list
    Node* head = node1;

    // Tail of the list

    Node* tail = node2;

    // Printing the linked list
    // print(head);  // 5 -> 10 ->  NULL 
    cout<<endl;

    // // Inserting at head
    // insertAtHead(head,25);
    // print(head);// 25 -> 5 -> 10 ->  NULL

    // Inserting at tail
    // insertAtTail(tail,35);
    // print(head); 
    // insertAtTail(tail, 50); 
    // print(head); 

    // Insert at a position 
    insertAtPosition(head,tail,4,55);
    print(head); 
    return 0;
}