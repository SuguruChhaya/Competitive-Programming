#include <bits/stdc++.h>
using namespace std;
long long n, m;
map<vector<long long>, vector <vector <long long>>> d;
vector <vector <bool>> visited, can_visit;

bool more_conditions(long long i, long long j){
    if (i-1>=1 && visited[i-1][j]){
        return true;
    }
    if (i+1<=n && visited[i+1][j]){
        return true;
    }
    if (j-1>=1 && visited[i][j-1]){
        return true; 
    }
    if (j+1<=n && visited[i][j+1]){
        return true;
    }
    return false;
}

void floodfill(long long i, long long j){
    if ((i==1 && j==1) || i>=1 && i<=n && j>=1 && j<=n && !visited[i][j] && more_conditions(i, j)){
        visited[i][j] = 1;
        for (auto v:d[{i, j}]){
            floodfill(v[0], v[1]);
        }
    }
    //!Something like the previous model with work better. 
}

int main(){
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (long long i=0;i<m;i++){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        d[{x, y}].push_back({a, b});
    }
    visited.resize(n+1, vector<bool>(n+1, 0));
    can_visit.resize(n+1, vector <bool>(n+1, 0));
    floodfill(1, 1);
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            ans += can_visit[i][j];
        }
    }
    //!Rooms that she can illuminate vs rooms she can travel to?
    
    cout << ans-1 << endl;
}