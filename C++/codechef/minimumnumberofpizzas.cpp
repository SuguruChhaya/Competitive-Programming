#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    //*n, k can be upto 10^9 which worries me...
    long long num = k, den = n, mod=-1;
    while (mod!=0){
        mod = k % n;
        k = n;
        n = mod;
    }
    //num = num / k;
    den = den / k;
    cout << den << endl;
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}