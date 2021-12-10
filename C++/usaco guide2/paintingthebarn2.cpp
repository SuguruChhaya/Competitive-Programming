#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> arr (1000, vector<long long>(1000, 0));
    for (long long i=0;i<n;i++){
        long long r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        for (long long row=r1;row<r2;row++){
            for (long long col=c1;col<c2;col++){
                arr[row][col]++;
            }
        }
    }
    long long ans = 0;
    for (long long i=0;i<1000;i++){
        for (long long j=0;j<1000;j++){
            ans += (arr[i][j]==k);
        }
    }
    cout << ans << endl;
}