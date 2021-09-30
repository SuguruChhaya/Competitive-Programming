#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> connections, coords;
vector <bool> used;
long long min_x, min_y, max_x, max_y;

void dfs(long long index){
    //cout << index << endl;
    if (used[index]==0){
        used[index]=1;
        min_x = min(min_x, coords[index][0]);
        max_x = max(max_x, coords[index][0]);
        min_y = min(min_y, coords[index][1]);
        max_y = max(max_y, coords[index][1]);
        for (auto e:connections[index]){
            dfs(e);
        }
    }
}
int main(){
    //*Store the connections. 
    //*Do a DFS, for every distinct connected component. 
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    coords.resize(n+1, vector <long long>(2));
    connections.resize(n+1);
    for (long long i=1;i<=n;i++){
        cin >> coords[i][0] >> coords[i][1];
    }
    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    long long result = 999999999999;
    used.resize(n+1, 0);
    //!Checking where it starts with all the cows. 
    //!Cannot for loop, just while I guess. 
    long long curr = 1;
    while (curr<=n ){
        if (used[curr]!=1){
            min_x =  9999999999999;
            min_y = 9999999999999;
            max_x =  -1;
            max_y = -1;
            dfs(curr);
            result = min(result, 2 * (max_x-min_x) + 2* (max_y-min_y));
            //!It probably stops when we hit a point. 
        }
        curr++;
    }

    cout << result << endl;
}