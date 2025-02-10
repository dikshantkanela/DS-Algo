#include <bits/stdc++.h>
using namespace std;

void moveZeros(int arr[], int n) {
    int i = 0; // fills non-zero elements

    for (int j = 0; j < n; j++) { // traverse
        if (arr[j]!=0) { // AGAR EK ELEMENT VI 0 NAHI HUA TO SWAP KRDO ith POSITION PE WHICH IS THE POSITION WHERE THE NON_ZERO ELEMENT HAS TO BE THERE
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12, 0, 5}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeros(arr, n);

    cout << "Array after moving zeros: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
