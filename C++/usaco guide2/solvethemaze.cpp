#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
vector <vector <char>> grid;
vector <vector <bool>> visited;
bool ok;
void floodfill(long long i, long long j){
    if (i>=0 && i<n && j>=0 && j<m && grid[i][j] != '#' && !visited[i][j]){
        visited[i][j] = 1;
        floodfill(i-1, j);
        floodfill(i+1, j);
        floodfill(i, j-1);
        floodfill(i, j+1);
    }
}
void solve(){
    cin >> n >> m;
    grid.clear();
    grid.resize(n, vector <char>(m));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            if (grid[i][j]=='B'){
                //!Need to make sure I don't block a 'B' nearby. 
                if (i-1>=0){
                    if (grid[i-1][j]=='G'){
                        cout << "NO" << endl;
                        return;
                    }
                    else if (grid[i-1][j]!='B'){
                        grid[i-1][j] = '#';
                    }
                }
                if (i+1<n){
                    if (grid[i+1][j]=='G'){
                        cout << "NO" << endl;
                        return;
                    }
                    else if (grid[i+1][j]!='B'){
                        grid[i+1][j] = '#';
                    }
                }
                if (j-1>=0){
                    if (grid[i][j-1]=='G'){
                        cout << "NO" << endl;
                        return;
                    }
                    else if (grid[i][j-1]!='B'){
                        grid[i][j-1] = '#';
                    }
                }
                if (j+1<m){
                    if (grid[i][j+1]=='G'){
                        cout << "NO" << endl;
                        return;
                    }
                    else if (grid[i][j+1]!='B'){
                        grid[i][j+1] = '#';
                    }
                }

                //*After all this, clear the vector visited. 

            }
        }
    }
    /*
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (long long a=0;a<n;a++){
        for (long long b=0;b<m;b++){
            if (grid[a][b]=='G'){
                //*Floodfill it. 
                visited.clear();
                visited.resize(n, vector<bool>(m,0));
                //ok = true;
                //
                floodfill(a, b);
                /*
                for (long long i=0;i<n;i++){
                    for (long long j=0;j<m;j++){
                        cout << visited[i][j] << " ";
                    }
                    cout << endl;
                }
                */
                if (!visited[n-1][m-1]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
    
}
int main(){
    
    cin >> t;
    while (t--){
        solve();
    }
}