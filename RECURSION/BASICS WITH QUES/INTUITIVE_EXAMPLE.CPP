#include<bits/stdc++.h>
using namespace std;

void reachHome(int src, int dest){
    cout<<"Source : "<< src<< " Destination : "<< dest<<endl;
    if(src == dest){  // base case
        cout<<"Reached!";
        return;
    }
    
    
    src++; // processing 
    reachHome(src,dest); // recursive call
}

int main(){
    int src = 1;
    int dest = 10;
    reachHome(src,dest);
    
    return 0;
}