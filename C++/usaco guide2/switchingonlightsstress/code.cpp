#include <bits/stdc++.h>
using namespace std;
map<vector<long long>, vector <vector <long long>>> d;
long long n, m;
vector <vector <bool>> on, visited;
vector <long long> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
vector <vector <vector <vector <long long>>>> arr;
bool hasVisitedNeighbor(long long i, long long j){
    for (long long a=0;a<dx.size();a++){
        if (i+dx[a]>=1 && i+dx[a]<=n && j+dy[a]>=1 && j+dy[a]<=n && on[i+dx[a]][j+dy[a]]){
            return true;
        }
    }
    return false;
}

void floodfill(long long i, long long j){
    if (i>=1 && i<=n && j>=1 && j<=n && !visited[i][j]){
        visited[i][j] = 1;
        for (auto v:arr[i][j]){
            if (!on[v[0]][v[1]]){
                on[v[0]][v[1]] = 1;
                if (hasVisitedNeighbor(v[0], v[1])){
                    floodfill(v[0],v[1]);
                }
            }
        }
        for (long long a = 0;a<dx.size();a++){
            long long nx = i + dx[a], ny = j+dy[a];
            if (nx >= 1 && nx <=n && ny >= 1 && ny <= n && on[nx][ny]){
                floodfill(nx, ny);
            }
        }
    }
}   

int main(){
    freopen("test", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    /*
    for (long long i=0;i<m;i++){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        d[{x, y}].push_back({a, b});
    }
    */
    arr.resize(n+1, vector <vector <vector <long long>>>(n+1));
    for (long long i=0;i<m;i++){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        arr[x][y].push_back({a, b});
    }
    //!Could it possibly be hashmap colliding or some shit?

    on.resize(n+1, vector <bool>(n+1, 0));
    on[1][1] =1;
    visited.resize(n+1, vector<bool>(n+1, 0));
    floodfill(1,1);
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            ans += on[i][j];
        }
    }
    cout << ans << endl;
}