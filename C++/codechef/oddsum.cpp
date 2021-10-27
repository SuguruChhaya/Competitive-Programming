#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--){
        long long n, ans = 1;
        cin >> n;
        ans += (n-1) * (n-2);
        cout << ans;
    }
}