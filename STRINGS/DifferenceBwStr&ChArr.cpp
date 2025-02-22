#include <bits/stdc++.h>
using namespace std;
int main()
{
    char text1[10] = "ab\0cd\0";
    cout<<strlen(text1); //2
    cout<<text1<<endl; //ab
    string text2 ="ab\0cd\0";
    cout<<text2; //ab
    char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // MUST BE MANUALLY NULL TERMINATED
    cout<<strlen(str); //5 will not count \0!
    return 0;
}