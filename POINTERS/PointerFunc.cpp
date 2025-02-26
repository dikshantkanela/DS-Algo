#include<bits/stdc++.h>
using namespace std;
void print(int *ptr){
    cout<<*(ptr);
}

void update(int *ptr, int *arr){ //this is a pointer to the array
     cout<< sizeof(arr)<<endl; //8(pointer hai!) not 40 // *arr == arr[] as parameter
    *ptr = *ptr + 2;
     cout<<"Inside Function"<< *ptr<<endl; // 12
}

int main(){
    int ans = 10;
    int *ptr = &ans;
    int arr[5] = {1,2,3,4,5};
    update(ptr,arr);
    cout<<"Outside Function : "<<*ptr << endl; //12
   
   
    return 0;
}