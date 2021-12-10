#include <bits/stdc++.h>
using namespace std;

set <vector<long long>> visited;
long long ans = 0;

void dfs(vector<long long> arr){
    if (!visited.count(arr)){
        visited.insert(arr);
        long long total = 0;
        for (auto e:arr){
            total+=e;
        }
        ans = max(ans, total);
        for (long long i=0;i<arr.size();i++){
            for (long long j=0;j<arr.size();j++){
                if (i!=j && arr[i]%2==0){
                    auto nextArr = arr;
                    nextArr[i] /=2;
                    nextArr[j] *= 2;
                    dfs(nextArr);
                }
            }
        }
    }
}

void solve(){
    visited = {};
    ans = 0;
    long long n;
    cin >> n;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    dfs(arr);
    cout << ans << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}