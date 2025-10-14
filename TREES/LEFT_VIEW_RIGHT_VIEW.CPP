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

void printLeftView(Node* root,vector<int> &view, int level){
    if(root == NULL){
        return;
    }

    if(view.size() == level){
        view.push_back(root->data);
        
    }

    printLeftView(root->left, view, level+1);
    printLeftView(root->right,view,level+1);

}

void printRightView(Node* root,vector<int>&rightView, int level){
    if(root == NULL){
        return;
    }
    
    if(rightView.size() == level){
        rightView.push_back(root->data);
    }

    printRightView(root->right,rightView,level+1);
    printRightView(root->left,rightView,level+1);



}

// without using vector!

void right(Node* root,int &count,int level){
    if(root == NULL){
        return;
    }
    if(count == level){
        cout<<root->data<<" ";
        count++; // similar to pushing into array!
    }

    right(root->right,count,level+1);
    right(root->left,count,level+1);
}


int main(){
    Node* root = createTree();
    levelOrder(root);
    // int level = 0;
    // vector<int> view;
    // printLeftView(root,view,level);

    // for(int i=0;i<view.size();i++){
    //     cout<<view[i]<<" ";
    // }
    // cout<<endl;
    // vector<int> rightView;
    // printRightView(root,rightView,level);

    //  for(int i=0;i<rightView.size();i++){
    //     cout<<rightView[i]<<" ";
    // }
    int count = 0;
    right(root,count,0);

    return 0;
}