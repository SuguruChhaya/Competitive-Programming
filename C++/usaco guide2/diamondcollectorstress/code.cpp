#include <bits/stdc++.h>
using namespace std;

int main(){
    //!The wrong assumption is that the next block will start right after. 
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long l1=0, r1=0, l2=0, r2;
    long long ans = 0;
    while (l1<n){
        while (r1<n&&arr[r1]-arr[l1]<=k){
            r1++;
        }
        l2=r1;
        if (l1==0){
            r2 = l2;
        }
        while (r2<n&&arr[r2]-arr[l2]<=k){
            r2++;
        }
        ans = max(ans, r2-l1);
        l1++;
    }
    cout << ans << endl;
}