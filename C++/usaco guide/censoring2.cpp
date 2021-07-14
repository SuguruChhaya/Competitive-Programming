#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main(){
    //*The whole point of this problem is to learn how to substring stuff and implement. 
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, t, newstring;
    cin >> s >> t;

    for (long long i=0;i<s.size();i++){
        //*Increase and keep reading. 
        //*I can erase last elementof a string using pop_back.
        //!Check whether the size matches as well.  
        newstring.push_back(s[i]);
        //!The substring is not necessarily i because it could have gone through delete operations. 
        //*
        if (newstring.size()>=t.size() && newstring.substr(newstring.size()-t.size(), t.size())==t){
            //*Remove the characters. 
            for (long long i=0;i<t.size();i++){
                newstring.pop_back();
            }
            
        }
    }
    cout << newstring << "\n";  
}