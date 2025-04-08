#include <bits/stdc++.h>
using namespace std;

// partition function used in quick sort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        if (i < j) { // ensures that in the last call it does not swap
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]); // places the pivot at correct index
    return j; // it is j which is the pivot's correct index and when j crosses i it is that place!
}

// quick sort recursive function
void qS(vector<int> &arr, int low, int high) {
    if (low < high) {
        int partIndex = partition(arr, low, high);
        qS(arr, low, partIndex - 1);
        qS(arr, partIndex + 1, high);
    }
}

// main quickSort function
vector<int> quickSort(vector<int> arr) {
    int low = 0;
    int high = arr.size() - 1;
    qS(arr, low, high);
    return arr;
}

// main function to test quickSort
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> sortedArr = quickSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
