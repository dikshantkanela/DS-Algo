/*
Approach:
- We're given two arrays: nums1 and nums2.
- For each element in nums1, we want to find the next greater element in nums2 (to its right).
- Traverse nums2 from right to left and use a stack to keep track of next greater elements.
- Use a map to store the next greater element for each number in nums2.
- Then, for each number in nums1, use the map to get the result.

Time Complexity: O(n + m)
    - n = size of nums2, m = size of nums1
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        int n = nums2.size();
        int m = nums1.size();
        vector<int> solution(m);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]){
                int top = st.top();
                st.push(nums2[i]);
                mp[nums2[i]] = top;
            }

            else{
                st.push(nums2[i]);
                mp[nums2[i]] = -1;
            }
        }
        
        for(int i=0;i<m;i++){
            solution[i] = mp[nums1[i]];
        }
        return solution;    
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
