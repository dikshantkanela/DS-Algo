#include <bits/stdc++.h>
using namespace std;

// Function to find the row with the maximum sum
pair<int, int> maxRowSum(const vector<vector<int>>& mat) {
     int maxi = INT_MIN;
     int rowNumber;
   

     for(int i=0;i<mat.size();i++){
        int sum = 0;
        for(int j=0;j<mat[i].size();j++){
            sum+=mat[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowNumber = i;
        }
  
     }
     return {rowNumber,maxi};

}


int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {0, 0, 0, 50}
    };

    pair<int, int> result = maxRowSum(mat);
    cout << "Maximum row sum is in row " << result.first << " with sum = " << result.second << endl;

    return 0;
}
