#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute-force Approach: O(n^2)
    int celebrityBruteForce(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int ans = -1;
        
        for(int i=0;i<rows;i++){
            bool iKnowsNone = true;
            bool everyoneKnowsi = true;
            for(int j=0;j<cols;j++){
                if(i!=j && mat[i][j] == 1){
                    iKnowsNone = false;
                    break;
                }
            }
            if(iKnowsNone){
                for(int k=0;k<rows;k++){
                    if(mat[k][i] == 0){
                        everyoneKnowsi = false;
                    }
                }
                if(everyoneKnowsi){
                    ans = i;
                }
                
                
            }
            
        }
    return ans;
    }

    // Stack-based Optimized Approach: O(n)
    int celebrityStack(vector<vector<int>>& mat) {
        int rows = mat.size();
        stack<int> st;
        
        for(int i=0;i<rows;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(mat[a][b] == 1){ // a knows b
                if(mat[b][a] == 0){
                    st.push(b);
                }
                
            }
            
            if(mat[b][a] == 1){
                if(mat[a][b] == 0){
                    st.push(a);
                }
            }
            
        }
        if(st.empty()){
            return -1;
        }
        int candidate = st.top();
        
        for(int i=0;i<rows;i++){
            if(i!=candidate){
                if(mat[candidate][i] == 1 || mat[i][candidate] == 0){
                    return -1;
                }
            }
        }
        return candidate;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int celebBrute = sol.celebrityBruteForce(mat);
    int celebStack = sol.celebrityStack(mat);

    cout << "Brute-force Approach: ";
    if (celebBrute != -1)
        cout << "Celebrity is at index " << celebBrute << endl;
    else
        cout << "No celebrity found." << endl;

    cout << "Stack-based Approach: ";
    if (celebStack != -1)
        cout << "Celebrity is at index " << celebStack << endl;
    else
        cout << "No celebrity found." << endl;

    return 0;
}
