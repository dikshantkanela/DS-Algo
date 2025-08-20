#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        int target = len - n;

        // Case: remove head
        if (target == 0) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
        else {
            int count = 0;
            ListNode* temp = head;
            while (count < target - 1 && temp->next != NULL) {
                count++;
                temp = temp->next;
            }

            ListNode* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }

        return head;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(arr);
    cout << "Original List: ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
