#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<vector<long long>> arr, prefix;

long long at(long long i, long long j){
    if (i>=0&&i<n&&j>=0&&j<n){
        return arr[i][j];
    }
    return 0;
}

int main(){
    cin >> n >> k;
    arr.resize(n, vector<long long>(n));
    arr.resize(n, vector<long long>(n, 0));
    vector<vector<long long>> arr (n, vector<long long>(n)), prefix(n, vector<long long>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    long long curr = 0;
    for (long long i=0;i<=k;i++){
        for(long long j=0;j<=k-i;j++){
            curr+=arr[i][j];
        }
    }
    prefix[0][0] = curr;
    long long ans = curr;
    for (long long i=0;i<=k;i++){
        for (long long j=0;j<=k;j++){
            if (!(i==0&&j==0)){
                if (j==0){
                    long long curr = prefix[i-1][0];
                    for(long long row=i-1-k;row<=i-1;row++){
                        curr -= at(row, k-1-(i-1-row));
                    }
                    for (long long row=i;row<=i+k;i++){
                        curr+=at(row, k-1-(row-i));
                    }
                    prefix[i][j]=curr;
                    ans = max(ans, curr);
                }
                else{
                    long long curr = prefix[i][j-1];
                    for (long long row=i-k;row<=i+k;row++){
                        curr-=at(row, j-1-(k-abs(row-i)));
                    }
                    for (long long row=i-k;row<=i+k;row++){
                        curr+=at(row, j+(k-abs(row-i)));
                    }
                    prefix[i][j] = curr;
                    ans = max(ans, curr);
                }
            }
        }
    }
    cout << ans << endl;
}