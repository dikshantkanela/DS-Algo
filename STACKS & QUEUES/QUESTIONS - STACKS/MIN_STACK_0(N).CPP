#include<bits/stdc++.h>
using namespace std;

class MinStack {
    public: 
        stack<int> st;
        stack<int> minSt;
        
        MinStack() {
            
        }
        
        void push(int val) {
            st.push(val); // push to main stack
            if(minSt.empty() || st.top() <= minSt.top()){ // if new min, push to min stack
                minSt.push(val);
            }
        }
        
        void pop() {
            if(!st.empty()){
                int top = st.top(); // this is to be popped 
                st.pop();
                if(top == minSt.top()){ // pop from min stack if equal
                    minSt.pop();
                }
            }
        }
        
        int top() {
            if(!st.empty()){
                return st.top(); // return top element
            }
            else{
                return -1;
            }
        }
        
        int getMin() {
            if(!minSt.empty()){
                return minSt.top(); // return current min
            }
            else{
                return -1;
            }
        }
    };
    

int main(){
    
    return 0;
}

