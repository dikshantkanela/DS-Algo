#include<bits/stdc++.h>
using namespace std;
//MUST SPECIFY DATA-TYPE OF FUNC LIKE int, void, string, etc
string greeting(string name){
    return "Hello " + name ;
}
int main(){
    string username;
    cin>>username;
    string result = greeting(username);
    cout<<result;
    return 0;
}