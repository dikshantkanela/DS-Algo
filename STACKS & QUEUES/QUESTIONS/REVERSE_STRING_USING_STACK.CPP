#include<bits/stdc++.h>
using namespace std;

int main(){
    string name = "Dikshant";
    
    stack<char> storeName;

    for(char ch:name){
        storeName.push(ch);
    }
    cout<<"Topmost element : "<< storeName.top()<<endl;


    string reverseName = "";


    while(!storeName.empty()){
        reverseName.push_back(storeName.top());
        storeName.pop();
    }
    cout<<"Reverse Name is :"<<reverseName;


    return 0;
}