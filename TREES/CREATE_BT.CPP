#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
        }
};

Node* createTree(){
    int data;
    cout<<"Enter the value for Node : "<<endl;
    cin>>data;
    // base case : 
    if(data == -1){
        return NULL;
    }
    // step 1 : make a root node
    Node* root = new Node(data);

    // step 2 : create left node : 
    // cout<<"Left Node for Node : "<<root->data<<endl;

    root->left = createTree();

    
    // step 3 : create right node : 
    // cout<<"Right Node for Node : "<<root->data<<endl;
    root->right = createTree();
}

void preOrderTraversal(Node* root){
    
    if(root == NULL){
        return;
    }

    // N : 
    cout<<root->data<< " ";

    // L : 
    preOrderTraversal(root->left);

    // R : 
    preOrderTraversal(root->right);

}

void inOrderTraversal(Node* root){

    if(root == NULL){
        return;
    }

        // L : 
    inOrderTraversal(root->left);

    // N : 
    cout<<root->data<<" ";
    
    // R : 
    inOrderTraversal(root->right);

}

void postOrderTraversal(Node* root){

    if(root == NULL){
        return;
    }

    // L : 
    postOrderTraversal(root->left);

    // R : 
    postOrderTraversal(root->right);
    
    // N : 
    cout<<root->data<<" ";

}


int main(){
    Node* root = createTree();
    cout<<root->data <<endl;

    // preOrderTraversal(root);
    // cout<<endl;
    // inOrderTraversal(root);
    // cout<<endl;
    // postOrderTraversal(root);
    // cout<<endl;



    



    return 0;
}