#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){
        long long g, c;
        cin >> g >> c;

        long long ans = pow(c, 2) / (2*g);
        cout << ans << "\n";
    }
}