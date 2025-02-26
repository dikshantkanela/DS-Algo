#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10] = {2,3,1,5,4,8};
    cout<<arr<<endl; //first index
    cout<<*arr<<endl; //2
    cout<<*arr+3<<endl; // 2+3=5
    cout<<arr[3]<<endl; //5
    cout<<*(arr+3)<<endl; //5

    //WOW FORMULA* : 
    int i = 4;
    cout<< i[arr]<<endl; // FORMULA : arr[i] ==> *(arr+i) or *(i+arr) ==> i[arr] = *(i+arr)
    int *ptr = arr;
    cout<< sizeof(ptr); // 4 or 8

   
    cout << "Address of whole array (&arr): " << &arr << endl; // SAME ANS
    cout << "Address of first element (arr): " << arr << endl; // SAME ANS

    // pointer ka address : 
    int temp[10] = {1,2,3,4,5,6};
    int *pntr = &temp[0];
    cout<<&pntr<<endl;
    // array ka address : 
    cout<<&temp[0]<<endl;
    cout<<temp;
    return 0;
}