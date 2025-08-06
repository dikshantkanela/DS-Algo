
#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    // Create a result vector to store the wave pattern
    vector<int> res;

    // Traverse each column from left to right
    for(int i = 0; i < mCols; i++){
     
        // If the column index is even, go top to bottom
        if(i % 2 == 0){
            for(int j = 0; j < nRows; j++){
                res.push_back(arr[j][i]);  // Push element from top to bottom
            }      
        }
        else{
            // If the column index is odd, go bottom to top
            for(int j = nRows - 1; j >= 0; j--){
                res.push_back(arr[j][i]);  // Push element from bottom to top
            }
        }
    }

    // Return the final wave-formed result
    return res;
}

int main(){
    
    return 0;
}
