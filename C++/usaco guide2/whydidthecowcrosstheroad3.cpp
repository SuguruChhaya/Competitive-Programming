#include <bits/stdc++.h>
using namespace std;
long long n, k, r;
vector <vector <vector <bool>>> arr;
vector <vector <bool>> visited;
void floodfill(long long i, long long j){
    if (i>=1 && i<=n && j>=1 && j<=n && !visited[i][j]){
        visited[i][j]=1;
        if (!arr[i][j][0]){
            floodfill(i-1, j);
        }
        if (!arr[i][j][1]){
            floodfill(i+1, j);
        }
        if (!arr[i][j][2]){
            floodfill(i, j-1);
        }
        if (!arr[i][j][3]){
            floodfill(i, j+1);
        }
    }
}
int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    arr.resize(n+1, vector <vector<bool>>(n+1, vector <bool>(4)));
    vector <vector <long long>> cows;
    
    for (long long i=0;i<r;i++){
        long long r1, c1, r2, c2;
        cin >> r1>>c1>>r2>>c2;
        if (r1<r2){
            //*Facing south from r1 would be r2
            arr[r1][c1][1] = 1;
            arr[r2][c2][0] = 1;
        }
        else if (r1>r2){
            arr[r1][c1][0] = 1;
            arr[r2][c2][1] = 1;
        }
        //north, south, west, east
        else if (c1<c2){
            //*Facing east from c1 will be c2
            arr[r1][c1][3] = 1;
            arr[r2][c2][2] = 1;
        }
        else{
            arr[r1][c1][2] = 1;
            arr[r2][c2][3] = 1;
        }
    }
    for (long long i=0;i<k;i++){
        long long r, c;
        cin >> r >> c;
        cows.push_back({r, c});
    }
    long long ans=0;
    //!Issue of counting reverse pairs. 
    
    for (long long i=0;i<k;i++){
        visited.clear();
        visited.resize(n+1, vector <bool>(n+1, 0));
        floodfill(cows[i][0], cows[i][1]);
        for (long long j=i+1; j<k;j++){
            if (!visited[cows[j][0]][cows[j][1]]){
                ans++;
            }
        }
    }
    cout << ans << endl;
}