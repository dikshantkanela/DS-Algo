#include<bits/stdc++.h>
using namespace std;

int powerOf2(int n){
    if(n == 0){
        return 1;
    }

    /*  int smallerProblem = powerOf2(n-1);
     int biggerProblem = 2*smallerProblem; 
    */

    return 2*powerOf2(n-1);
};

int main(){
    int n;
    cin>>n;
    int res = powerOf2(n);
    cout<< res;
    return 0;
}