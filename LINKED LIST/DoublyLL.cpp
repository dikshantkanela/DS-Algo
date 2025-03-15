#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <--> "; // print the data of node
        temp = temp->next;

    }

    cout<<"NULL";
}

int findLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp!=NULL){
       temp = temp->next;
       len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    // FOR EMPTY LL
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }

    Node* temp = new Node(data);
    temp->prev = NULL; // not needed though
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head,Node* &tail, int data){
    // FOR EMPTY LL
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }
    int count = 1;
    Node* temp = head;
    while(count<position-1 && temp->next != NULL){ // ensure if user enters any invalid position like 100
        temp = temp->next; // temp ko insertion position ke ek node peeche le jaa
        count++;
    }
    // sahi insertion matlab count == position-1
    // galat insertion count<position-1
     // ✅ Out of bounds check
     if (count < position - 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if(temp->next == NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert ->next = temp->next;
    nodeToInsert ->prev = temp;
    temp->next -> prev = nodeToInsert;
    temp->next = nodeToInsert;
    
}

void deleteAtPosition(Node* &head, Node* &tail, int position){
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
    
        if(position == 1){
        Node* temp = head;
        if(head->next != NULL){  // 🔹 Case 1: More than one node in the list
            temp->next->prev = NULL; 
            head = temp->next;
            
        }
          // 🔹 Case 2: Only one node in the list
         else {
           head = NULL;
           tail = NULL;
        }
        delete temp;
        return;
        }

        else{
            Node* temp = head;
            int count = 1;
            while(count<position-1 && temp->next!=NULL){
                temp = temp->next;
                count++;
            }

           // ✅ Out of Bounds Check
            if (temp->next == NULL) {
              cout << "Wrong position!" << endl;
              return;
         }

            Node* nodeToDelete = temp->next;
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;

            if(nodeToDelete->next == NULL){ // ensures updating the tail when tail is deleted
                temp -> next = NULL;
                tail = temp;
               

            }
            delete nodeToDelete;
        }
    }

int main(){
        Node* node1 = new Node(10);
        Node* node2 = new Node(11);
        Node* head = node1; 
        Node* tail = node2; 
        node1->next = node2;
        node2->prev = node1;

    print(head); // initial print
    cout<<endl;
    
    insertAtHead(head,tail,9); // insertions at head
    // print(head);
    insertAtHead(head,tail,8);
    // print(head);
    insertAtHead(head,tail,7);
    // print(head);

    insertAtTail(head,tail,12); // insertion at tail 
    // print(head);
    insertAtPosition(head,tail,13,2);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,5);
    print(head);
    cout<<endl;
    
    cout<<"Length: " << findLength(head);
    return 0;
}