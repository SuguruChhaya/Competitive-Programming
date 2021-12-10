#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<bool>>visited(2001, vector<bool>(2001));
    long long n;
    cin >> n;
    long long row = 1000, col=1000;
    map <char, vector <long long>> d = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'W', {0, -1}},
        {'E', {0, 1}}
    };
    for (long long i=0;i<n;i++){
        char c;
        cin >> c;
        visited[row][col] = 1;
        row+=d[c][0], col+=d[c][1];
    }
    long long ans = -1;
    for (long long i=0;i<2001;i++){
        for (long long j=0;j<2001;j++){
            if (!visited[i][j]){
                ans++;
                queue<vector<long long>> q;
                q.push({i, j});
                while (!q.empty()){
                    auto curr = q.front();
                    cout << curr[0] << " " << curr[1] << endl;
                    q.pop();
                    if (curr[0]>=0 && curr[0]<2001 && curr[1]>=0 && curr[1]<2001 && !visited[curr[0]][curr[1]]){
                        visited[curr[0]][curr[1]] = 1;
                        q.push({curr[0]-1, curr[1]});
                        q.push({curr[0]+1, curr[1]});
                        q.push({curr[0], curr[1]+1});
                        q.push({curr[0], curr[1]-1});
                    }
                }
            }
        }
    }
    cout << ans << endl;
}