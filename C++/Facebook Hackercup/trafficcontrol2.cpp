#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{   cout<<"Case #"<<t<<": ";
    int n, m,a,b;
    cin>>n>>m>>a>>b;
    int grid[n][m];
    memset(grid , -1 , sizeof(grid));
    int tempb = b;
    int left = 0;
    int bottom = 0;
    int steps = n+m-1;
    bool flag = true;
    if(steps>a || steps>b)flag = false;
    if(flag){//possible
        //fillA
        cout<<"Possible"<<endl;
        for(int i=0;i<n;i++){
            grid[i][0] = 1;
            a--;
        }
        for(int j = 1;j<m-1;j++){
            grid[n-1][j] = 1;
            a--;
        }
        grid[n-1][m-1] = a;
        
        
        
        b-=n;
        
     
        for(int j = 1;j<m-1;j++){
            grid[0][j] = 1;
            b--;
        }
        grid[0][m-1] = b;
        
    
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == -1)grid[i][j] = 1000;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        
        
    }else{
        cout<<"Impossible"<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    int i =1;
    while (t--)
    {
        solve(i);
        i++;
    }
    return 0;
}