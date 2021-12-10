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
    long long r = n/2, l=r-1;
    cout << arr[r] - arr[l] + 1 << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}