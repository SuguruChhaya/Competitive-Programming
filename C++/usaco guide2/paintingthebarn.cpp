#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> arr (1001, vector<long long>(1001, 0));
    for (long long i=0;i<n;i++){
        long long row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        arr[row1][col1]++;
        arr[row2][col2]++;
        arr[row1][col2]--;
        arr[row2][col1]--;
    }
    long long ans = 0;
    for (long long i=0;i<=1000;i++){
        for (long long j=0;j<=1000;j++){
            long long temp = arr[i][j];
            if (i-1>=0){
                temp+=arr[i-1][j];
            }
            if (j-1>=0){
                temp+=arr[i][j-1];
            }
            if (i-1>=0&&j-1>=0){
                temp-=arr[i-1][j-1];
            }
            arr[i][j] = temp;
            if (temp==k){
                ans++;
            }
        }
    }
    cout << ans << endl;
}