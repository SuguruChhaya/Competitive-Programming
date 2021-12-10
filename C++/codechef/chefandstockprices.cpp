#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    if (a<=s*(1+c/100.0) && s*(1+c/100.0)<=b){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}