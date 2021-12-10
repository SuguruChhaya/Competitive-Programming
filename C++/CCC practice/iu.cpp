#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long currI=0, ans = 0;
    for (long long i=0;i<2*n;i++){
        if (s[i]=='I'){
            ans += abs(currI-i);
            currI += 2;
        }
    }
    cout << ans << endl;
}