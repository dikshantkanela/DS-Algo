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

    root->left = createTree();
    root->right = createTree();
    
    return root;

}


void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* r = q.front();
        q.pop();

        if(r == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<r->data<< " ";
            if(r->left!=NULL){
                q.push(r->left);
            }
            if(r->right!=NULL){
                q.push(r->right);
            }

        }
        
    }

}

// hashmap mein daalenge : no need to check/push for null
void topView(Node* root){
    
    map<int,Node*> hdToNode;

    queue<pair<int,Node*>> q;

    q.push(make_pair(0,root));

    while(!q.empty()){
        pair<int,Node*> ele = q.front();
        q.pop();

        int hd = ele.first;
        Node* node = ele.second;

        if(hdToNode.find(hd) == hdToNode.end()){
            hdToNode[hd] = node;
        }

        if(node->left!=NULL){
            q.push(make_pair(hd-1,node->left));
        }

        if(node->right!=NULL){
            q.push(make_pair(hd+1,node->right));

        }


    }

    
        cout << "Top View: ";
    for (auto it : hdToNode) {
        cout << it.second->data << " ";
    }
    cout << endl;

     
     
}

void bottomView(Node* root){
    map<int,Node*> hdToNode;

    queue<pair<int,Node*>> q;

    q.push(make_pair(0,root));

    while(!q.empty()){
        pair<int,Node*> ele = q.front();
        q.pop();

        int hd = ele.first;
        Node* node = ele.second;

        // overwrite in every iteration :
         hdToNode[hd] = node;
        

        if(node->left!=NULL){
            q.push(make_pair(hd-1,node->left));
        }

        if(node->right!=NULL){
            q.push(make_pair(hd+1,node->right));

        }


    }

    
        cout << "Bottom View: ";
    for (auto it : hdToNode) {
        cout << it.second->data << " ";
    }
    cout << endl;
}


int main(){
    Node* root = createTree();
    levelOrder(root);
    cout << "\n";
    topView(root);
    cout << "\n";
    bottomView(root);

    



    
    return 0;
}