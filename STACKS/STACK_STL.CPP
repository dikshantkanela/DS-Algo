#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.pop();

    cout<<"Topmost Element is : "<< st.top()<<endl;
    cout<<"Is stack empty? :  "<< (bool) st.empty()<<endl;

    cout<<st.size();
    return 0;
}