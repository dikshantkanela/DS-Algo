#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {   
    vector<int> answer;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        } 
        else if (arr1[i] > arr2[j]) {
            j++;
        } 
        else { // if (arr1[i]==arr2[j])
            answer.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return answer;
}

int main() {
    int n = 8, m = 8; // Fixed size as 8
    vector<int> arr1(n), arr2(m);

    cout << "Enter 8 elements of first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter 8 elements of second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = findArrayIntersection(arr1, n, arr2, m);
    
    cout << "Intersection elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
