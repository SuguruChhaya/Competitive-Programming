#include <bits/stdc++.h>
using namespace std;
map <long long, set<long long>> d;
vector<vector<long long>> arr;
long long dfs(long long i, long long j, long long prev){
    if (arr[i][j]!=0){
        return arr[i][j];
    }
    else if (i==j){
        return 9999999999999;
    }
    else{
        long long mini = 9999999999999;
        //cout << d[i].size() << endl;
        //!Consider direct connections too. 
        //!Store prev. 
        for (auto e:d[i]){
            if (e!=j && e!=prev){
                mini = min(mini, arr[i][e]);
                mini = min(mini, dfs(e, j, i));
            }
        }
        arr[i][j] = mini;
        arr[j][i] = mini;
        return mini;
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
        arr[p][q] = r;
        arr[q][p] = r;
    }
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            //!Cannot go from same index to same index...
            /*
            if (i==1 && j==4){
                cout << "";
            }
            */
            
            if (i!=j){
                arr[i][j] = dfs(i, j, -1);
            }

        }
    }
    /*
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (long long i=0;i<q;i++){
        long long k, v;
        long long ans = 0;
        cin >> k >> v;
        for (long long j=1;j<=n;j++){
            ans += (arr[v][j]>=k);
        }
        cout << ans << endl;
    }
}