#include<bits/stdc++.h>
using namespace std;


int main(){
    queue<int> q;
    q.push(1);
    q.push(21);
    q.push(3);
    cout<< q.front()<<endl; // 1
    cout<< q.back()<<endl; // 3
    cout<<q.size()<<endl; // 3

    q.pop(); // 1 will be popped
    cout<< q.front()<<endl;
    cout<<q.back()<<endl; // 3
    
    cout<<q.empty(); // 0




    return 0;
}