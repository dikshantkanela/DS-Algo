#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

 ListNode* copyLL(ListNode* head){
        ListNode* newLL = new ListNode(head->val);
        ListNode* copy = newLL;
        ListNode* original = head->next;

        while(original!=NULL){
            copy->next = new ListNode(original->val);
            original = original->next;
            copy = copy->next;
        }

        return newLL;

    }