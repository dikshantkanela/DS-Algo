#include <iostream>
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

// Two-pointer method to find the middle node
Node* middleNodeTwoPointer(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Length-based method to find the middle node
Node* middleNodeLength(Node* head) {
    Node* lenTemp = head;
    int len = 0;
    while (lenTemp != NULL) {
        lenTemp = lenTemp->next;
        len++;
    }

    int mid = len / 2;
    Node* matchTemp = head;
    int count = 0;
    while (count < mid) {
        matchTemp = matchTemp->next;
        count++;
    }
    return matchTemp;
}

// Function to insert a node at the tail
void insertAtTail(Node* &tail, int data) {
    Node* nodeToInsert = new Node(data);
    if (tail == NULL) {
        tail = nodeToInsert;
    } else {
        Node* temp = tail;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeToInsert;
    }
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    
    cout << "Original List: ";
    print(head);
    
    Node* middle1 = middleNodeTwoPointer(head);
    cout << "Middle Node (Two Pointer): " << middle1->data << endl;
    
    Node* middle2 = middleNodeLength(head);
    cout << "Middle Node (Length Method): " << middle2->data << endl;
    
    return 0;
}
