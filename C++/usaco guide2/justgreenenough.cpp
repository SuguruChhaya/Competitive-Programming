#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long>(n));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    long long ans = 0;
    for (long long r1=0;r1<n;r1++){
        for (long long c1=0;c1<n;c1++){
            for (long long r2=r1;r2<n;r2++){
                for (long long c2=c1;c2<n;c2++){
                    long long mini = 9999999;
                    for (long long i=r1;i<=r2;i++){
                        for (long long j=c1;j<=c2;j++){
                            mini = min(mini, arr[i][j]);
                        }
                    }
                    if (mini==100){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}