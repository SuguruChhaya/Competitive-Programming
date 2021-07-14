#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    map <long long, long long> d;
    for (long long i=0;i<q;i++){
        long long decide;
        cin >> decide;
        if (decide==0){
            long long a, b;
            cin >> a >> b;
            //*I guess insertion fails if already exists. 
            if (d.count(a)==1){
                d[a] = b;
            }
            else{
                d.insert({a, b});
            }
        }
        else{
            long long a;
            cin >> a;
            if (d.count(a)==1){
                cout << d[a] << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }

    //*Removing key in a for loops c
    //*Instead I could just create a new map 
}