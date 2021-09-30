#include <bits/stdc++.h>
using namespace std;
bool cycle = 0;
vector <bool> visited;
vector <vector <bool>> arr;
long long n, k;
void dfs(long long original, long long i){
    //cout << i << endl;
    if (visited[i]==0){
        visited[i] = 1;
        for (long long j=1;j<=n;j++){
            if (arr[i][j]==1){
                dfs(original, j);
            }
        }
    }
    else if (i==original){
        cycle=1;
    }
}
int main(){
    
    cin >> n >> k;
    arr.resize(n+1, vector <bool>(n+1, 0));
    visited.resize(n+1, 0);
    //*Don't think I need -1;
    for (long long i=0;i<k;i++){
        long long a, b, s_a, s_b;
        cin >> a >> b >> s_a >> s_b;
        arr[a][b] = (s_a>s_b);
        arr[b][a] = (s_b>s_a);
    }
    long long ans = 0;
    
    for (long long i=1;i<=n;i++){
        cycle =0;
        visited.clear();
        visited.resize(n+1, 0);
        dfs(i, i);
        if (cycle){
            ans++;
        }
    }
    cout << ans << endl;
    
}