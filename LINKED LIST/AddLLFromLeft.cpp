#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Default constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next pointer
};

class Solution {
public:
    // Function to add two linked lists representing numbers
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = NULL; // Head of the result list
        ListNode* ansTail = NULL; // Tail of the result list

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = 0;
            int val2 = 0;

            if (l1 != NULL) {
                val1 = l1->val;
            }
            if (l2 != NULL) {
                val2 = l2->val;
            }

            int sum = val1 + val2 + carry; // Sum of corresponding digits + carry
            int res = sum % 10; // Extract last digit
            carry = sum / 10; // Extract carry for next iteration

            insertAtTail(res, ansHead, ansTail); // Insert the digit into result list

            if (l1 != NULL) {
                l1 = l1->next; // Move to next node in l1
            }   

            if (l2 != NULL) {
                l2 = l2->next; // Move to next node in l2
            }
        }
        return ansHead; // Return the final result list
    }

    // Function to insert a digit at the tail of the linked list
    void insertAtTail(int digit, ListNode* &head, ListNode* &tail) {
        ListNode* temp = new ListNode(digit);
        if (head == NULL) {
            head = temp; // If list is empty, set head and tail to new node
            tail = temp;
        } else {
            tail->next = temp; // Append new node to the end
            tail = temp; // Update tail
        }
    }

    // Function to call add function and return result
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1, l2);
        return ans;
    }
};
