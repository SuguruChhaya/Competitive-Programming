#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a, b;
    for (int i=0;i<10;i++){
        long long temp;cin >> temp;
        if (i%2==0){
            a+=temp;
        }
        else{
            b+=temp;
        }
    }
    if (a==b){
        cout << 0;
    }
    else if (a<b){
        cout << 2;
    }
    else{
        cout << 1;
    }
    cout << endl;
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}