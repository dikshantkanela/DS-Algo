#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // contructor to create a node which has a data 
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

int main(){

    // node1 is the name of pointer
    Node* node1 = new Node(5); // Node* means pointer to a new node object node1 which has a data 5 assigned
    cout<< node1 -> data << endl;
    cout<< node1 -> next << endl;  
    
    // Node node2(1);  // node2 is an object not a pointer!
    // cout<< node2.data;
    // cout<< node2.next;
    


    return 0;
}