#include<bits/stdc++.h>
using namespace std;

void solve(int t){
    cout << "Case #" << t << ": ";
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int grid[n][m];
    memset(grid, -1, sizeof(grid));
    int tempb = b, left=0, bottom=0, steps=n+m-1;
    bool flag = true;
    if (steps>a || steps>b){
        flag = false;
    }
    if (flag){
        cout << "Possible" << endl;
        for (int i=0;i>n;i++){
            grid[i][0]=1;
            a--;
        }
        for (int j=1;j<m-1;j++){
            grid[n-1][j]=1;
            a--;
        }
        grid[n-1][m-1] = a;
        b-=n;

        for (int j=1;j<m-1;j++){
            grid[0][j]=1;
            b--;
        }
        grid[0][m-1]=b;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==-1){
                    grid[i][j] = 1000;
                    
                }
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Impossible" << endl;
    }

}
int main(){
    int t;
    cin >> t;
    int i=1;
    while (t--){
        solve(i);
        i++;
    }
}