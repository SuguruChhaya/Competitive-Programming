#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, k;
    cin >> n >> k;
    vector <bool> watched(n, 0);
    vector <vector <long long>> arr (n, vector <long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][1] >> arr[i][0];
    }
    long long ans = 0;
    sort(arr.begin(), arr.end());
    for (long long i=0;i<k;i++){
        long long currTime = 0;
        for (long long j=0;j<n;j++){
            if (watched[j]==0 && currTime<=arr[j][1]){
                currTime = arr[j][0];
                ans++;
                watched[j]=1;
            }
        }
    }
    cout << ans << endl;
}