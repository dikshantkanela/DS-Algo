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

// Function to detect a loop in the linked list
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Function to insert a node at the tail
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* nodeToInsert = new Node(data);
    if (tail == NULL) {
        head = tail = nodeToInsert;
    } else {
        tail->next = nodeToInsert;
        tail = nodeToInsert;
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
    Node* head = NULL;
    Node* tail = NULL;
    int n, data;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, tail, data);
    }
    
    cout << "Original List: ";
    print(head);
    
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    
    return 0;
}
