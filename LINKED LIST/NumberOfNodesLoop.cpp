#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if (head == NULL || head->next == NULL) {
            return 0;
        }
        
        Node* slow = head;
        Node* fast = head;
        bool loopExists = false;
        int len = 0;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                loopExists = true;
                break;
            }
        }
        
        if (!loopExists) {
            return 0;
        }
        
        while (fast->next != slow) {
            fast = fast->next;
            len++;
        }
        
        return len + 1;   
    }
};

//  (IGNORE)
Node* createLinkedList(vector<int> &values, int loopPos) {
    if (values.empty()) return NULL;
    
    Node* head = new Node(values[0]);
    Node* tail = head;
    Node* loopNode = NULL;

    for (int i = 1; i < values.size(); i++) {
        tail->next = new Node(values[i]);
        tail = tail->next;

        if (i == loopPos - 1) {
            loopNode = tail;
        }
    }

    if (loopPos != 0) {
        tail->next = loopNode;
    }

    return head;
}

// Function to test the countNodesinLoop function
void testFunction() {
    vector<int> values = {1, 3, 2, 4, 5, 6};
    int loopPos = 2;  // Creates a loop at position 2

    Node* head = createLinkedList(values, loopPos);
    Solution obj;
    cout << "Loop Length: " << obj.countNodesinLoop(head) << endl;
}

int main() {
    testFunction();
    return 0;
}
