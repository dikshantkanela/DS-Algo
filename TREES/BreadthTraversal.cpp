#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createBinaryTree(){
    int data;
    cout<<"Enter the Node : ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    // for left node : 
    root->left = createBinaryTree();
    // for right node : 
    root->right = createBinaryTree();

}

void levelTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* r = q.front();
        q.pop();
        // if the node is a NULL node : 
        if(r == NULL){ // front element is NULL means that the current level is printed and also, all the children of next level are already there in the queue so we need to insert NULL for the next level!! 
            cout<<endl; // we guarantee that the new level is gonna start!
            if(!q.empty()){
                q.push(NULL); // if the queue gets empty at this state means all elements are done!
            }
            
        }

        // if the node is a normal node
        else{
            cout<<r->data<<" "; // fetch the front node data (print)
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

    Node* root = createBinaryTree();
    levelTraversal(root);
    
    return 0;
}