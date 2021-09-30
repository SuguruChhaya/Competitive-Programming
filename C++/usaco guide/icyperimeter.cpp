#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> grid, perm, visited;
long long n, ans_size=-1, ans_perm=-1, curr_size, curr_perm;

void fill(long long i, long long j){
    if (i>=0 && i<n && j>=0 && j<n && grid[i][j] && visited[i][j]==0){
        visited[i][j]=1;
        curr_size++;
        curr_perm+=perm[i][j];
        fill(i+1, j);
        fill(i-1, j);
        fill(i, j+1);
        fill(i, j-1);
    }
}
int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    grid.resize(n, vector <long long>(n, 0));
    perm.resize(n, vector <long long>(n, 0));
    visited.resize(n, vector <long long>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            char c;
            cin >> c;
            if (c=='#'){
                //cout << grid.size() << endl;
                grid[i][j]=1;
                perm[i][j]+=4;
                if (i-1>=0&&grid[i-1][j]==1){
                    perm[i-1][j]--;
                }
                if (i+1<n){
                    perm[i+1][j]--;
                }
                if (j-1>=0&&grid[i][j-1]==1){
                    perm[i][j-1]--;
                }
                if (j+1<n){
                    perm[i][j+1]--;
                }
            }
            

        }
    }
    //*No idea about how to find perimeter...
    //*All sides have 4 by default.
    /*
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cout << perm[i][j] << " ";
        }
        cout << endl;
    }
    */

    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            curr_size = 0, curr_perm = 0;
            fill(i, j);
            //!Want the perimeter to be smaller. 
            if (curr_size>ans_size || (ans_size==curr_size && curr_perm<ans_perm)){
                ans_size = curr_size;
                ans_perm = curr_perm;
            }
        }
    } 
    cout << ans_size << " " << ans_perm << endl;
}