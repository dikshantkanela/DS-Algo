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
    // Function to get the length of the linked list
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // Base cases: empty list or single node is always a palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Finding the middle of the linked list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        // Get the length to check if odd-length list, move slow ahead
        // FOR EVEN WE NEED TO REVERSE INCLUDING THE MID BUT FOR NOT WE NEED TO GO AHEAD
        int len = getLength(head);
        if (len % 2 != 0) {
            slow = slow->next; 
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr != NULL) {
            ListNode* nextPart = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPart;
        }

        // Compare the first half and the reversed second half
        ListNode* startPt = head;
        ListNode* midNextPt = prev;
        
        while (midNextPt != NULL) {
            if (startPt->val == midNextPt->val) {
                startPt = startPt->next;
                midNextPt = midNextPt->next;
            } else {
                return false;
            }
        }
        return true;    
    }
};

// Function to create a linked list from a vector of values
ListNode* createLinkedList(vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code
int main() {
    vector<int> values = {1, 2, 3, 2, 1};
    ListNode* head = createLinkedList(values);
    
    Solution sol;
    bool result = sol.isPalindrome(head);
    
    cout << "Is Palindrome: " << (result ? "Yes" : "No") << endl;
    return 0;
}
