#include <bits/stdc++.h> 
using namespace std;

vector<int> sumOfMaxAndMin(vector<int> &arr, int n, int k) {
    vector<int> res;
    deque<int> min;
    deque<int> max;

    for(int i=0;i<k;i++){
        while(!min.empty() && arr[i]<arr[min.back()]){
            min.pop_back();
        }
        while(!max.empty() && arr[i]>arr[max.back()]){
            max.pop_back();
        }
        min.push_back(i);
        max.push_back(i);   
    }
   res.push_back(arr[max.front()] + arr[min.front()]);
    // access the extra element that comes into new window and remove the front element from the queue which is out of window since we dont have to access that 
    for(int i=k;i<n;i++){
        while(!min.empty() && i-min.front()>=k){
            min.pop_front();
        }
        while(!max.empty() && i-max.front()>=k){
            max.pop_front();
        }
        while(!min.empty() && arr[i]<arr[min.back()]){
            min.pop_back();
        }
        while(!max.empty() && arr[i]>arr[max.back()]){
            max.pop_back();
        }
        min.push_back(i);
        max.push_back(i);
        res.push_back(arr[max.front()] + arr[min.front()]);
    }
    return res; // contains sum of max and min of the current window

}
