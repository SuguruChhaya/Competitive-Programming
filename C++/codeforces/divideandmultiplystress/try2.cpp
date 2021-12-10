#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long temp = 0;
    for (long long i=0;i<n;i++){
        while (arr[i]%2==0){
            temp++;
            arr[i] /=2;
        }
    }
    sort(arr.begin(), arr.end());
    arr[n-1] *= pow(2, temp);
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
    
    //solve();
}