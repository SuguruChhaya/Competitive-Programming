#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long l = 0;
    while (l<n-1){
        while (l<n-1 && arr[l]%2==1){
            l++;
        }
        if (l!=n-1){
            while (arr[l]%2==0){
                arr[l] /=2;
                arr[n-1] *=2;
            }
        }
    }
    long long ans = 0;
    for (auto e:arr){
        ans+=e;
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