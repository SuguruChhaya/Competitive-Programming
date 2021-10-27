#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector <vector <long long>> arr (n, vector<long long>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    /*
    vector <vector <
    long long ans = 0;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            deque <vector <long long>> q;
            q.push_back({i, j, 0, -1});
            while (!q.empty()){
                auto curr = q[0];
                q.pop_front();
                if (curr[4]==k){
                    ans = max(
                }
            }
        }
    }
    */
    //?No idea how to rotate the matrix. 
    vector <vector <long long>> arr (2*n-1, vector <long long>(2*n-1, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
}