#include <bits/stdc++.h>
using namespace std;
long long n, m;
map<vector<long long>, vector <vector <long long>>> d;
vector <vector <bool>> visited, can_visit;

void floodfill(long long i, long long j){
    if (i>=1 && i<n && j>=1 && j<m && can_visit[i][j] && !visited[i][j]){
        visited[i][j]=1;
        for (auto v: d[{i, j}]){
            bool ok = false;
            if (v[0]-1>=1 && visited[v[0]-1][v[1]]){
                ok = true;
            }
            if (v[0]+1<n && visited[v[0]+1][v[1]]){
                ok = true;
            }
            if (v[1]-1>=1 && visited[v[0]][v[1]-1]){
                ok = true;  
            }
            if (v[1]+1<m && visited[v[0]][v[1]+1]){
                ok = true;
            }
            if (ok){
                can_visit[v[0]][v[1]]=1;
                floodfill(v[0], v[1]);
            }
        }
    }
}
int main(){
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (long long i=0;i<m;i++){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        d[{x, y}].push_back({a, b});
        //visited.resize(n+1, vector <long long>(n+1));
    }
    visited.resize(n+1, vector <bool>(m+1, 0));
    can_visit.resize(n+1, vector <bool> (m+1, 0));
    can_visit[1][1] = 1;
    floodfill(1, 1);
    long long ans = 0;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            if (visited[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
}