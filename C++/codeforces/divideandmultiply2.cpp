#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long r = -1;
    for (long long i=0;i<n;i++){
        if (arr[i]%2==1){
            r=i;
        }
    }
    if (r==-1){
        r = n-1;
    }

    for (long long i=0;i<n;i++){
        if (i!=r){
            while (arr[i]%2==0){
                arr[i]/=2;
                arr[r]*=2;
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