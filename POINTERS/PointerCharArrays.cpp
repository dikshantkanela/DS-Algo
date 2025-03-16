#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch[5] = "Jeep"; // 5th element is \0
    char *c = &ch[0]; // or ch only 
    cout<<c<<endl; // *FULL char array! SINCE COUT BEHAVES DIFFERENTLY FOR CHAR ARRAYS, WILL PRINT UNTILL \0 IS FOUND
    cout<<*c<<endl;  // J
    //* to get address of char array : 
    cout<<&ch<<endl; // pointer to the whole char array
    cout<<&ch[0]<<endl; // print full array ==>same as telling cout<<ch
 
    // char character = 'c';
    // char *pt = &character;
    // cout<<pt; // c and random stuff untill \0 found : c▒☻♂♦
    return 0;
}   