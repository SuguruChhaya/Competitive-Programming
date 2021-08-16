#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long temp;
    long long c1=0, c2=0;
    for (long long i=1;i<=6;i++){
        cin >> temp;
        if (i<=3){
            c1+=temp;
        }
        else{
            c2+=temp;
        }
    }
    if (c1 > c2){
        cout << "1" << endl;
    }
    else{
        cout << "2" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t; cin >> t;
    while (t--){
        solve();
    }
}