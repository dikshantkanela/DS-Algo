#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/* ----------------------------- APPROACH 1 -----------------------------
   ✅ Using Extra Space (vector to store the path)
----------------------------------------------------------------------- */
class SolutionWithVector {
  public:
    bool solve(Node* root, int node, vector<int>& path) {
        if (root == NULL) return false;

        path.push_back(root->data);
        if (root->data == node) return true;

        bool leftAns = solve(root->left, node, path);
        bool rightAns = solve(root->right, node, path);

        if (leftAns || rightAns) return true;

        // backtrack if not found in this path
        path.pop_back();
        return false;
    }

    int kthAncestor(Node *root, int k, int node) {
        vector<int> path;
        bool found = solve(root, node, path);

        if (!found) return -1;
        int n = path.size();
        if (n - k - 1 >= 0)
            return path[n - k - 1];
        else
            return -1;
    }
};

/* ----------------------------- APPROACH 2 -----------------------------
   ✅ Without Extra Space (Recursion + Backtracking)
----------------------------------------------------------------------- */
class SolutionWithoutVector {
  public:
    Node* solve(Node* root, int &k, int node) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == node) {
            return root;
        }

        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        if(leftAns == NULL && rightAns!=NULL){
            k--;
            if(k == 0){
                k = INT_MAX;
                return root;
            }
            
        }

        else if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k == 0){
                k = INT_MAX;
                return root;
            }
        }

        else{
            return NULL;
        }
        

    }

    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        if (ans == NULL || ans->data == node)
            return -1;
        return ans->data;
    }
};

/* ----------------------------- MAIN FUNCTION ----------------------------- */
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2, node = 5;

    SolutionWithVector s1;
    SolutionWithoutVector s2;

    cout << "Approach 1 (With vector): " << s1.kthAncestor(root, k, node) << endl;
    cout << "Approach 2 (Without vector): " << s2.kthAncestor(root, k, node) << endl;

    return 0;
}
