#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

//0(n) SPACE: 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns

        // Initialize two arrays to keep track of which rows and columns
        // need to be set to zero
        vector<int> rowZero(m, 0); // rowZero[i] == 1 means row i should be set to 0
        vector<int> colZero(n, 0); // colZero[j] == 1 means column j should be set to 0

        // First pass: identify all rows and columns that contain at least one zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = 1; // mark the row
                    colZero[j] = 1; // mark the column
                }
            }
        }

        // Second pass: update the matrix
        // If either the row or column for a given element was marked,
        // set that element to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowZero[i] == 1 || colZero[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// 0(1) SPACE : 
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();    // number of rows
        int n = arr[0].size(); // number of columns

        int col0 = 1; // to track if the first column should be set to 0

        // Step 1: Traverse the matrix and use the first row and first column 
        // as markers to indicate whether a row or column should be zeroed.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    if (j == 0) {
                        // If the zero is in the first column,
                        // mark col0 = 0 and continue (we use a separate flag for col0)
                        arr[i][j] = 0;
                        col0 = 0;
                    } else {
                        // Otherwise, mark the first row and first column
                        // to indicate the entire row and column should be zeroed
                        arr[0][j] = 0; // mark column
                        arr[i][0] = 0; // mark row
                    }
                }
            }
        }

        // Step 2: Use the markers to set appropriate cells to zero
        // Skip the first row and column for now
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] != 0) {
                    // If either the row marker or column marker is 0, set cell to 0
                    if (arr[i][0] == 0 || arr[0][j] == 0) {
                        arr[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: Handle the first row separately if it originally had any zero
        if (arr[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                arr[0][i] = 0;
            }
        }

        // Step 4: Handle the first column separately if col0 flag is set
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                arr[i][0] = 0;
            }
        }
    }
};
