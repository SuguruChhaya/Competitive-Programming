#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<bool> own(2*n+1, 1);
    vector<long long> arr;
    for (long long i=0;i<n;i++){
        long long a;
        cin >> a;
        own[a] = 0;
        arr.push_back(a);
    }
    long long ans = 0;
    for (long long i=0;i<n;i++){
        long long l=arr[i], r=2*n-1, ok=-1;
        while (l<=r){
            long long mid = (l+r)/2;
            //!If we don't have it, it doesn't mean it doesn't exist. 
            //*Still have to check lower. 
            if (own[mid]){
                ok = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if (ok!=-1){
            own[ok] = 0;
            ans++;
        }
        //cout << own[j] << endl;
        /*
        while (j<2*n+1&&!own[j]){
            j++;
        }
        *
        if (j<2*n+1){
            ans++;
            own[j] = 0;
        }
        */
    }
    cout << ans << endl;
}