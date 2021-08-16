#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long p;
        cin >> p;
        if (p % 2==0){
            cout << 2 << " " << p << "\n";
        } 
        else{
            cout << 2 << " " << (p-1) << "\n";
        }
    }
}