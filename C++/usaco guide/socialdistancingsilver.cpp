#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector <vector <long long>> arr (m, vector <long long>(2));
    for (long long i=0;i<m;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    long long l=0, r=arr[m-1][1]-arr[0][0], ans;
    while (l<=r){
        long long mid = (l+r)/2;
        bool ok=true;
        long long last = 0, currInterval = 0;
        for (long long i=0;i<n;i++){
            if (i==0){
                last = arr[0][0];
            }
            else{
                while (currInterval<m&&arr[currInterval][1]<last+mid){
                    currInterval++;
                }
                if (currInterval==m){
                    ok = false;
                    break;
                }
                else{
                    last = max(arr[currInterval][0], last+mid);
                }
            }
        }
        if (ok){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}