#include<bits/stdc++.h>
using namespace std;
int main(){

    map<string,int> mp;
    // insert : 
    pair<string,int> p1 = make_pair("Dikshant",100 );
    mp.insert(p1);

    pair<string,int> p2("Daksh",82);
    mp.insert(p2);

    mp["Chaman"] = 83;

    // update : 
    mp["Chaman"] = 90;

    // access : 
    cout<< mp["Dikshant"]; // 100
    cout<<endl;

    cout<< mp.at("Dikshant"); // 100
    cout<<endl;

    // cout<<mp.at("Lassi"); // error
    cout<<mp["Lassi"]; // 0
     cout<<endl;
    cout<<mp.at("Lassi"); // 0
     cout<<endl;

    // iterate : 
    for(auto it = mp.begin();it!=mp.end();++it){ // since its a map keys will be taken in asc order
        cout<<it->first<< " :  "<< it->second;
        cout<<endl;
    }

    for(auto &p:mp){
        cout<<p.first<< " :  "<< p.second;
        cout<<endl;
    }
    






    
    return 0;
}