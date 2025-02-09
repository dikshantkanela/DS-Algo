#include <bits/stdc++.h>
using namespace std;

bool arraySortedOrNot(vector<int>& arr) {
    // code here
    bool sorted = false;
    for(int i=0;i<arr.size();i++){
        if(i+1<arr.size() && arr[i+1]<arr[i]){
            sorted = false;
            return sorted;
        }
        
        else{
            sorted = true;
        }
    }
return sorted;    
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Example input
    cout << (arraySortedOrNot(arr) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}
