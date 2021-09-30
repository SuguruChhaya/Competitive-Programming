#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("convention.out", "w", stdout);
    long long n, m, c;
    cin >> n >> m >> c;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long l=0, r=arr[n-1]-arr[0], ans=-1;
    while (l<=r){
        long long mid = (l+r)/2;
        cout << mid << endl;
        bool ok = true;
        long long numBusses = m, currStart = arr[0], numCows=0;
        for (long long i=0;i<n;i++){

            if (arr[i]-currStart>mid || numCows>=c){
                currStart=arr[i];
                numBusses--;
                numCows=0;
            }
            if (numBusses<=0){
                ok = false;
                break;
            }
            numCows++;
        }
        if (ok){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}