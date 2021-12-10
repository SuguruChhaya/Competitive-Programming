#include <bits/stdc++.h>
using namespace std;
map <long long, set<long long>> d;
vector<vector<long long>> arr;

vector<long long> dfs(long long i, long long j, long long prev){
    if (arr[i][j]!=0){
        return {j, arr[i][j]};
    }
    else{
        for (auto e:d[j]){
            if (e!=prev){
                auto temp = dfs(e, j, i);
                if (temp[0]==j){
                    arr[i][j] = min(temp[1], arr[i][e]);
                }
                return {j, arr[i][j]};
            }
        }
        return {-1, -1};
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    long long n, q;
    cin >> n >> q;
    arr.resize(n+1, vector<long long>(n+1, 0));

    for (long long i=0;i<n-1;i++){
        long long p, q, r;
        cin >> p >> q >> r;
        d[p].insert(q);
        d[q].insert(p);
        //?Don't know whether arr or map is faster. 
        arr[p][q] = r;
        arr[q][p] = r;   
    }

    for (long long i=0;i<q;i++){
        long long k, v, ans=0;
        cin >> k >> v;
        for (long long j=1;j<=n;j++){
            if (v!=j){  
                ans += (dfs(v, j, -1)[1]>=k);
            }
        }
        cout << ans << endl;
    }
}