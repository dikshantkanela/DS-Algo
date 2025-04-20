#include<bits/stdc++.h>
using namespace std;
class SpecialStack {
    public:
    int min = INT_MAX;
    stack<int> st;

    SpecialStack(){
       
    }

    void push(int data) {
        // if stack is empty, push data and update min
        if(st.empty()){
            st.push(data);
            min = data;
        }
        else{
            if(data < min){
                int new_data = 2 * data - min; // encode the value to store previous min
                st.push(new_data);
                min = data; // update min
            }
            else{
                st.push(data); // normal push
            }
        }
    }

    void pop() {
        // if popping encoded value, restore previous min
        if(!st.empty()){
            if(min > st.top()){
                min = 2 * min - st.top(); // restore previous min
                st.pop();
            }
            else{
                st.pop(); // normal pop
            }
        }
    }

    int top() {
        // return correct top based on encoded logic
        if(!st.empty()){
            if(st.top() < min){
                return min; // return actual top (decoded)
            }
            else{
                return st.top(); // return top as-is
            }
        }
        else{
            return -1;
        }
    }

    int getMin() {
        // return current min
        if(!st.empty()){
            return min;
        }
        else{
            return -1;
        }
    }  
};

int main(){
    
    return 0;
}

