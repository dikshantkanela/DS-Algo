// CEIL : THE SMALLEST NUMBER SUCH THAT IT IS >= THE TARGET VALUE (x) (LOWER BOUND KI VALUE)
// FLOOR : THE LARGEST NUMBER SUCH THAT IT IS <= THE TARGET VALUE (x)

#include <bits/stdc++.h>
using namespace std;

// Function to find the floor of x in the sorted array
int getFloor(vector<int>& a, int n, int x) {
    int start = 0, end = n - 1;
    int ans = -1;  // Default value when floor doesn't exist

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (a[mid] <= x) {
            ans = a[mid];  // This is a potential floor, continue searching for a larger one
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

// Function to find the ceiling of x in the sorted array
int getCeil(vector<int>& a, int n, int x) {
    int start = 0, end = n - 1;
    int ans = -1;  // Default value when ceiling doesn't exist

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (a[mid] >= x) {
            ans = a[mid];  // This is a potential ceiling, continue searching for a smaller one
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
    // Get the floor and ceiling values for x
    int floor = getFloor(a, n, x);
    int ceil = getCeil(a, n, x);
    return {floor, ceil};
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    pair<int, int> result = getFloorAndCeil(a, n, x);
    cout << result.first << " " << result.second << endl;

    return 0;
}
