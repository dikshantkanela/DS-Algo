// C++ program to find the sum
// of each row of a matrix
#include <bits/stdc++.h>
using namespace std;

vector<int> sumRow(vector<vector<int>> &mat) {
    vector<int> res;
    for(int i=0;i<mat.size();i++){
        int sum = 0; // re initialise after every iteration;
        for(int j=0;j<mat[i].size();j++){
            sum+=mat[i][j];
        }
        res.push_back(sum);
    }
    return res;

}

// Function to print the result vector
void printArray(vector<int> &arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        cout << "Sum of row " << i << " = " << arr[i] << endl;
    }
    cout << endl;
   
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = sumRow(mat);
    printArray(result, 4, 4);

    return 0;
}