#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next; // t1 just traverses and compares
            }

            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next; // t2 just traverses and compares
            }
            
        }  

        if(t1!=NULL){ // if elements of t1 remains use temp to connect/reach to them
            temp->next = t1;
          
        }
        else{
            temp->next = t2;  // if elements of t2 remains use temp to connect/reach to them
           
        }
        return dummy->next;
    }
};