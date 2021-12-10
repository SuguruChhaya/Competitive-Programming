#include <bits/stdc++.h>
using namespace std;
long long curr;
set <long long> ids;
vector<vector<bool>> visited;
long long n;
long long ans1 = 0, ans2 = 0;
vector<vector<long long>> arr;
void dfs(long long i, long long j, long long val){
    if (i>=0&&i<n&&j>=0&&j<n&&!visited[i][j]&&arr[i][j]==val){
        visited[i][j] = 1;
        curr++;
        dfs(i-1, j, val);
        dfs(i+1, j, val);
        dfs(i, j-1, val);
        dfs(i, j+1, val);
    }
}
void dfs2(long long i, long long j){
    if (i>=0&&i<n&&j>=0&&j<n&&!visited[i][j]){
        ids.insert(arr[i][j]);
        if (ids.size()>2){
            ids.erase(arr[i][j]);
        }
        else{
            visited[i][j] = 1;
            curr++;
            dfs2(i-1, j);
            dfs2(i+1, j);
            dfs2(i, j-1);
            dfs2(i, j+1);
        }

    }
}

int main(){
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);

    cin >> n;
    arr.resize(n, vector<long long>(n));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<long long>> regions;
    visited.resize(n, vector<bool>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (!visited[i][j]){
                curr = 0;
                dfs(i, j, arr[i][j]);
                //?If we aren't resetting the values, how can it be possible?
                ans1 = max(ans1, curr);
                regions.push_back({i, j});
            }
        }
    }
    for (auto e:regions){
        curr = 0;
        ids = {};
        visited = {};
        visited.resize(n, vector<bool>(n, 0));
        dfs2(e[0], e[1]);
        if (ids.size()==2){
            ans2 = max(ans2, curr);
        }
    }
    cout << ans1 << endl << ans2 << endl;
}   