#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[3][4]; // 3 rows and 4 colums
    // input
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter element of "<<i<<"row and "<<j<<"th column";
            cin>>arr[i][j];
        }
    }
    // output : row wise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    // output column wise : 
    for(int i=0;i<3;i++){ // number of columns here
        for(int j=0;j<3;j++){ // number of rows here
            cout<< arr[j][i];
        }
        cout<<endl;
    }
    
    return 0;
}