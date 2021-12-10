//?My guess is that we are doing too much recursion. 
#include <bits/stdc++.h>
using namespace std;
map <long long, set<long long>> d;
vector<vector<long long>> arr;
map <vector<long long>, long long> m;

long long dfs(long long i, long long j, long long prev, vector<vector<long long>> order){
    
    if (i==j){
        long long mini = 99999999999999;
        for (auto e:order){
            mini = min(mini, m[{e[0], e[1]}]);
        }
        return mini;
    }
    else{
        //!Only want to consider everything that was in the path. 
        //*Store in vector. Calculation comes later. 
        for (auto e:d[i]){
            if (e!=prev){
                //!Shouldn't be counting minimum for all because not all path. 
                //mini = min(m[{i, e}], mini);
                //mini = min(mini, dfs(e, j, i));
                auto nextOrder = order;
                nextOrder.push_back({i, e});
                long long temp = dfs(e, j, i, nextOrder);
                if (temp!=-1){
                    return temp;
                }
            }
        }
        return -1;
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
        m[{p, q}] = r;
        m[{q, p}] = r;
    }
    for (long long i=0;i<q;i++){
        long long k, v, ans=0;
        cin >> k >> v;
        for (long long j=1;j<=n;j++){
            if (v!=j){  
                ans += (dfs(v, j, -1, {})>=k);
            }
        }
        cout << ans << endl;
    }
}