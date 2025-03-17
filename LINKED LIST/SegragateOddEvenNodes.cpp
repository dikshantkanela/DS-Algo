#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;

        while (even != NULL && even->next != NULL) {
            // connect odd to next odd :
            odd->next = even->next; // next odd will be current even's next node
            odd = odd->next;

            // connect even to next even
            even->next = odd->next; // next even will be current odd's next node
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

// Function to create a linked list from a vector
ListNode* createLinkedList(vector<int> &values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;

    for (int i = 1; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }
    
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to test the oddEvenList function
void testFunction() {
    vector<int> values = {1, 2, 3, 4, 5, 6};
    
    ListNode* head = createLinkedList(values);
    cout << "Original List: ";
    printLinkedList(head);

    Solution obj;
    head = obj.oddEvenList(head);

    cout << "Reordered List: ";
    printLinkedList(head);
}

int main() {
    testFunction();
    return 0;
}
