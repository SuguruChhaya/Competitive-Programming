#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long l = 0, r = (arr[n-1]-arr[0]) / 2, ans;
    while (l<=r){
        long long mid = (l+r) / 2;
        vector <bool> detonated(n, 0);
        long long curr = 0, used = 0;
        while (curr<n){
            while (curr<n && detonated[curr]==1){
                curr++;
            }
            long long place = arr[curr]+mid;
            detonated[curr]=1;
            //!Not limited to the next value but can keep going on. 
            
            while(curr+1<n&&place+mid>=arr[curr+1]){
                detonated[curr+1]=1;
                curr++;
            }
            if (curr>=n){
                break;
            }
            used++;
        }
        if (used<=k){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;

}