#include<bits/stdc++.h>
using namespace std;
void printArray(int names[],int size){
   
}
int main(){
    // DECLARE AN ARRAY :
    int nums[10];
    // ACCESS ARRAY ITEMS : 
    cout<<"Element at 5th index : "<< nums[5]<<endl; // GARBAGE VALUE
    // INITIALISE :
    int grades[3] = {90,54,89};
    // ACCESS : 
    cout<<"Element at 2th index : "<< grades[2]<<endl; //89
    cout<<"Element at 4th index : "<< grades[4]<<endl; //out-of-bounds error
    //PRINTING ARRAY : 
    int n = 3;
    for(int i = 0;i<n;i++){
        cout<< grades[i]<<" ";
    }

    return 0;
}