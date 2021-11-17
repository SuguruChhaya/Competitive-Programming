#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    map <char, long long> d;
    for (long long i=0;i<s1.size();i++){
        d[s1[i]] = i;
    }

    long long ans = 0;
    for (long long i=0;i<s2.size()-1;i++){
        ans += abs(d[s2[i+1]]-d[s2[i]]);
    }
    cout << ans << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}