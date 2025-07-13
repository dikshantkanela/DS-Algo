#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][4] = {
        {42, 87, 14, 75},
        {36, 19, 23, 98},
        {51, 65, 72, 10}
    };
    int target;
    cout<<"ENTER ELEMENT TO SEARCH FOR : ";
    cin>>target;
    bool exists = false;
    // linear search - O(n2) complexity
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j] == target){
                exists = true;
                break; // else it will search the entire array
            }
        }
    }
    cout<< (exists==true?"true":"false");
    return 0;
}   