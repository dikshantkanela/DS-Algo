    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int number;
        cout<<"Enter the number : ";
        cin>>number;
        int numberTemp = number;
        int remainder;
        int reverse = 0;
        while(numberTemp>0){
            remainder = numberTemp%10;
            reverse = reverse*10 + remainder;
            numberTemp/=10;
        }
        cout<<"Reversed Number : "<<reverse<<endl;
        if(number == reverse){
            cout<<"Number is a palindrome";
        }
        else{
            cout<<"Number is not a palindrome";
        }
        return 0;
    }