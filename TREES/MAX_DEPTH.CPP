#include <iostream>
#include <algorithm>
using namespace std;

/*
Approach:
---------
1. If the root is NULL, it means the tree is empty, so depth = 0.
2. Recursively find the depth of the left subtree and the right subtree.
3. The depth of the tree is the maximum of left and right subtree depths + 1 (for the current node).
4. Base Case: When root = NULL → return 0.
This uses DFS recursion (Post-order traversal).
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with maxDepth function
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // Creating a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Maximum Depth of the Tree: " << sol.maxDepth(root) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
