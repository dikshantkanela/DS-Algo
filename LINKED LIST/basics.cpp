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

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &head, int data){
    
    if(head == NULL){
        head = new Node(data);
        return; 
    }
    Node* temp = head;
    
    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node* node = new Node(data);
    temp->next = node;

}

void insertAtPosition(Node* &head,int data,int pos){
    if(pos == 1){
        insertAtHead(head,data);
    }
    Node* temp = head;
    int count = 1;
    while(temp!=NULL && count<pos-1){
        temp = temp->next;
        count++;
    }
       // If position is out of bounds
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    Node* node = new Node(data);
    node->next = temp->next;
    temp->next = node;


}

void deleteNode(Node* &head, int pos){
    if(head == NULL){
        return;
    }
    if(pos == 1){ // for starting node
        Node* temp = head;
        head = temp->next;
        delete temp;
    }



    else{
        int count = 1;
        Node* curr = head;
        Node* prev = NULL;


        while(curr!=NULL && count<=pos-1){
            curr = curr->next;
            prev = prev->next;
            count++;
        }
        if(curr == NULL){
            cout << "Position out of range." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;


    }

}

int main(){
    Node* head = new Node(5);
    head->next = new Node(10);
    cout<<head->next->data;
    
    return 0;
}