#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, l, x;
        cin >> n >> l >> x;
        long long num = min(l, n-l);
        cout << num * x << endl;
    }
}