#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Print function for Circular Linked List
void print(Node* &tail) {
    if (tail == NULL) {
        cout << "LL is empty" << endl;
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(Head)" << endl;
}

// Insert at tail
void insertAtTail(Node* &tail, int data) {
    if (tail == NULL) {
        Node* nodeToInsert = new Node(data);
        tail = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    } else {
        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = tail->next;
        tail->next = nodeToInsert;
        tail = nodeToInsert;
    }
}

// Insert at head
void insertAtHead(Node* &tail, int data) {
    if (tail == NULL) {
        Node* nodeToInsert = new Node(data);
        tail = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    } else {
        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = tail->next;
        tail->next = nodeToInsert;
    }
}

// Insert at position
void insertAtPosition(Node* &tail, int data, int position) {
    if (position == 1 || tail == NULL) { // Insert at head case
        insertAtHead(tail, data);
        return;
    }

    Node* temp = tail->next;
    int count = 1;

    while (count < position - 1 && temp != tail) {
        temp = temp->next;
        count++;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if (temp == tail) { // If inserting at tail, update tail pointer
        tail = nodeToInsert;
    }
}

int main() {
    Node* tail = NULL;

    cout << "Initially: ";
    print(tail);

    cout << "\nInserting at Tail: 10, 20, 30" << endl;
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    print(tail);

    cout << "\nInserting at Head: 5" << endl;
    insertAtHead(tail, 5);
    print(tail);

    cout << "\nInserting at Position 3: 15" << endl;
    insertAtPosition(tail, 15, 3);
    print(tail);

    cout << "\nInserting at Position 1 (New Head): 1" << endl;
    insertAtPosition(tail, 1, 1);
    print(tail);

    cout << "\nInserting at Last Position: 35" << endl;
    insertAtPosition(tail, 35, 7);
    print(tail);

    return 0;
}
