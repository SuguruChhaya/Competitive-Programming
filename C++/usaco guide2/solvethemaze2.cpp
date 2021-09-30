//*Some optimizations:
//!If I know that a certain cell can reach, as soon as floodfill reaches that cell, we already know.
#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
vector <vector <char>> grid;
vector <vector <bool>> can_reach;
bool keep_going;
set <vector <long long>> visited;
void floodfill(long long i, long long j){
    /*
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cout << can_reach[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (i>=0 && i<n && j>=0 && j<m && can_reach[i][j]){
        keep_going = false;
        visited.insert({n-1, m-1});
    }
    if (keep_going && i>=0 && i<n && j>=0 && j<m && grid[i][j] != '#' && !visited.count({i, j})){
        visited.insert({i, j});
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
    can_reach.clear();
    can_reach.resize(n, vector <bool> (m, 0));
    for (long long a=0;a<n;a++){
        for (long long b=0;b<m;b++){
            if (grid[a][b]=='G'){
                //*Floodfill it. 
                //visited.clear();
                //visited.resize(n, vector<bool>(m,0));
                //ok = true;
                //'
                keep_going = true;
                visited.clear();
                floodfill(a, b);
                /*
                for (long long i=0;i<n;i++){
                    for (long long j=0;j<m;j++){
                        cout << visited[i][j] << " ";
                    }
                    cout << endl;
                }
                */
                if (visited.count({n-1, m-1})){
                    //!Maybe adding the last element is causing some issues here?
                    for (auto e:visited){
                        can_reach[e[0]][e[1]] = 1;
                    }
                }
                else{
                    /*
                    for (auto e:visited){
                        cout << e[0] << " " << e[1] << endl;
                    }
                    */
                   /*
                    for (long long i=0;i<n;i++){
                        for (long long j=0;j<m;j++){
                            cout << can_reach[i][j] << " ";
                        }
                        cout << endl;
                    }
                    */
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