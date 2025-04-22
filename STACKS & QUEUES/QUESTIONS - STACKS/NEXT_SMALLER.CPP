#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> nextSmallerElementBrute(vector<int> &arr, int n) {
    // Traverse the array from left to right
    for(int i = 0; i < n; i++) {
        int j = i + 1;

        // Find the first element smaller than arr[i] on its right
        while(j < n && arr[i] <= arr[j]) {
            j++;
        }

        // If no smaller element is found to the right
        if(j == n) {
            arr[i] = -1;
        } 
        // If a smaller element is found
        else {
            arr[i] = arr[j];
        }
    }

    // Return the updated array with next smaller elements
    return arr;
}

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        // Remove elements that are not smaller than arr[i]
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if(!st.empty() && st.top()<arr[i]){
            int top = st.top();
            st.push(arr[i]);
            arr[i] = top;

        }

        else if(st.empty()){
            st.push(arr[i]);
            arr[i] = -1;
        }

    }

    return arr;
}

// 🧪 Example usage
int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextSmallerElement(arr, arr.size());

    cout << "Next Smaller Elements: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
