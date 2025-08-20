
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
    int getDecimalValue(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int base = 1;
        int decimal = 0;

        for(int i=arr.size()-1;i>=0;i--){
            int lastDigit = arr[i];
            decimal+=lastDigit*base;
            base = base*2;
        }

        return decimal;
        

    }
};