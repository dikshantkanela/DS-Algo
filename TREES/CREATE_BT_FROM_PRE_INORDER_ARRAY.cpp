#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> mp;

    
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preorderIndex,int inorderStart,int inorderEnd,int n){
        if(preorderIndex>n-1 || inorderStart>inorderEnd){
            return NULL;
        }
    // Approach:
    // Ek case hum khud solve karte hain (current node banate hain),
    // baaki left aur right subtrees recursion sambhalta hai.
    int element = preorder[preorderIndex]; // current element in preorder array
    preorderIndex++; // move to next element for next call
    TreeNode* root = new TreeNode(element); // create node of the current element

    int findPos = mp[element]; // find the index in inorder array of the current element

    root->left = solve(preorder,inorder,preorderIndex,inorderStart,findPos-1,n);
    root->right= solve(preorder,inorder,preorderIndex,findPos+1,inorderEnd,n);

    return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n = preorder.size();
       int preorderIndex = 0;
       int inorderStart = 0;
       int inorderEnd = inorder.size()-1;
       // for searching in map : 0(1) complexity
       for(int i=0;i<inorder.size();i++){
           mp[preorder[i]] = i;

       }
       TreeNode* ans = solve(preorder,inorder,preorderIndex,inorderStart,inorderEnd,n);
    }
};

// Helper function to print inorder traversal of the built tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
