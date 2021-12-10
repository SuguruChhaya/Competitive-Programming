#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long l1=0, r1=0, l2=0, r2=0;
    long long ans = 0;
    while (l1<n){
        //!r1 will always be on or below l1. 
        while (r1<n&&arr[r1]-arr[l1]<=k){
            r1++;
        }
        l2=r1;
        r2 = max(r2, l2);
        //!I think sometimes r2 could be behind l1. 
        while (r2<n&&arr[r2]-arr[l2]<=k){
            r2++;
        }
        ans = max(ans, r2-l1);
        l1++;
    }
    cout << ans << endl;
}