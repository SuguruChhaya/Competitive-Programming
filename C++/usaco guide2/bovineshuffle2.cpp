#include <bits/stdc++.h>
using namespace std;
bool ok;
vector <bool> visited;
vector <vector <long long>> opposite;
void trace_back(long long i){
    if (!ok && !visited[i]){
        visited[i] = 1;
        for (auto e:opposite[i]){
            trace_back(e);
        }
    }
    else{
        ok = true;
    }
}
int main(){
    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);
    long long n;
    cin >> n;
    opposite.resize(n+1);
    for (long long i=1;i<=n;i++){
        long long temp;
        cin >> temp;
        opposite[temp].push_back(i);
    }
    vector <bool> checked (n+1, 0);
    long long ans = 0;
    visited.resize(n+1, 0);
    for (long long i=1;i<=n&&!checked[i];i++){
        for (long long j=1;j<=n;j++){
            visited[j] =0;
        }
        ok = false;
        trace_back(i);
        if (ok){
            ans++;
        }
    }
    cout << ans << endl;
}