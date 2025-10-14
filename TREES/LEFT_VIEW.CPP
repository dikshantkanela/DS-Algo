#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    int val;
    cout<<"Enter the value of Node : ";
    cin>>val;

    if(val == -1){
        return NULL;
    }
    
    Node* root = new Node(val);

    root->left = createTree(); // left node
    root->right = createTree(); // right node

    return root; // return the base root node


}

void preOrder(Node* root){

    if(root == NULL){
        return;
    }

    // Current Node (N)
    cout<<root->data<< " ";
    // Left Node (L)
    preOrder(root->left);
    // Right Node (R)
    preOrder(root->right);

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    // LNR

    preOrder(root->left);

    cout<<root->data<< " ";

    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    // LRN

    postOrder(root->left);

    cout<<root->data<< " ";

    postOrder(root->right);

}
 
// does NOT use recursion!
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* r = q.front();
        q.pop();

        if(r == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
           
             cout<<endl;
            
        }

        else{
            cout<<r->data<<" ";
            if(r->left!=NULL){
                q.push(r->left);
            }
            if(r->right!=NULL){
                q.push(r->right);
            }
        }
    }
}

int main(){
    Node* root = createTree();
    levelOrder(root);

    return 0;
}