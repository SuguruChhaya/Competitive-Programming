#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long>(n)), sumsBelow(n, vector<long long>(n+1, 0)), sumsAtMost(n, vector<long long>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            sumsBelow[i][j+1] = sumsBelow[i][j] + (arr[i][j]<100);
            sumsAtMost[i][j+1] = sumsAtMost[i][j]+(arr[i][j]<=100);

        }
    }
    long long ans = 0;
    for (long long x1=0;x1<n;x1++){
        for (long long x2=x1+1;x2<=n;x2++){
            
        }
    }
}