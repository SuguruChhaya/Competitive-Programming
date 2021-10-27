#include <bits/stdc++.h>
using namespace std;
map<vector<long long>, vector <vector <long long>>> d;
vector <vector <bool>> visited, lit;
long long n, m;

bool can_visit(long long i, long long j){
    if (i==1 && j==1){
        return true;
    }
    if (lit[i][j]){
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
    }
    return false;
}

void floodfill(long long i, long long j){
    //cout << i << " " << j << endl;
    if (i>=1 && i<=n && j>=1 && j<=n && !visited[i][j] && can_visit(i, j)){
        visited[i][j]=1;
        for (auto v:d[{i, j}]){
            lit[v[0]][v[1]]=1;
        }
        floodfill(i-1, j);
        floodfill(i+1, j);
        floodfill(i, j-1);
        floodfill(i, j+1);
    }
}
int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (long long i=0;i<m;i++){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        d[{x, y}].push_back({a, b});
    }
    visited.resize(n+1, vector <bool>(n+1, 0));
    //can_visit.resize(n+1, vector <bool>(n+1, 0));
    lit.resize(n+1, vector <bool>(n+1, 0));
    //can_visit[1][1] =1;
    lit[1][1] = 1;
    floodfill(1, 1);
    
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            if (lit[i][j] && !visited[i][j]){
                floodfill(i, j);
            }
        }
    }
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            ans += lit[i][j];
            
            if (lit[i][j]){
                //cout << i << " " << j << endl;
            }
            
        }
    }
    cout << ans << endl;
}