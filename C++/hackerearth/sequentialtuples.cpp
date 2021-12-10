#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr = {0, 1, 3, 6, 8};
    long long lastNum = 1, ans = 0;
    while (lastNum<=4 && lastNum<=n){
        ans += arr[lastNum];
        lastNum++;
    }
    lastNum--;
    ans+=9*(n-lastNum);
    cout << ans << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}