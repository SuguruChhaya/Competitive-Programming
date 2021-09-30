#include <bits/stdc++.h>
using namespace std;
vector <vector <char>> arr;
vector <vector <bool>> visited;
long long n, m;
void floodfill(long long i, long long j){
    if (i<0 || i>=n || j<0 || j>=m || arr[i][j]!='.' || visited[i][j]){
        return;
    }
    else{
        visited[i][j] = 1;
        floodfill(i, j + 1);
        floodfill(i, j - 1);
        floodfill(i - 1, j);
        floodfill(i + 1, j);
    }
}
int main(){
    
    cin >> n >> m;
    arr.resize(n, vector <char>(m));
    visited.resize(n, vector <bool>(m, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    long long ans = 0;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            if (arr[i][j]=='.'&&visited[i][j]==0){
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}