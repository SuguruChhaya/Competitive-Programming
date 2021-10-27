#include <bits/stdc++.h>
using namespace std;
long long fence_size = 2001;
vector <vector <long long>> visited (fence_size, vector <long long>(fence_size, 0));
/*
void floodfill(long long i, long long j){
    //cout << i << " " << j << endl;
    if (i==1 && j==1){
        cout << "";
    }
    if (i>=0 && i<fence_size && j>=0 && j<fence_size && visited[i][j]==0){
        visited[i][j]=1;
        floodfill(i-1, j);
        floodfill(i+1, j);
        floodfill(i, j-1);
        floodfill(i, j+1);
    }
}
*/
//!Maybe it is just a recursion limit thing. 

int main(){
    long long n;
    string s;
    cin >> n >> s;
    //cout << visited.size() << endl;
    vector <long long> curr = {1000, 1000};
    //cout << "ok" << endl;
    visited[curr[0]][curr[1]] = -1;
    //cout << "ok1" << endl;
    map <char, vector <long long>> d = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'W', {0, -1}},
        {'E', {0, 1}}
    };
    long long temp = 0;
    for (auto e:s){
        curr[0] += d[e][0];
        curr[1] += d[e][1];
        visited[curr[0]][curr[1]] = -1;
        temp++;
    }
    //cout << temp << endl;
    
    long long ans = 0;
    //set <vector <long long>> se;
    for (long long i=0;i<fence_size;i++){
        for (long long j=0;j<fence_size;j++){
            if (visited[i][j]==0){
                //floodfill(i, j);
                ans++;
                deque <vector <long long>> q;
                q.push_back({i, j});
                while (!q.empty()){
                    auto curr = q[0];
                    q.pop_front();
                    if (curr[0]>=0 && curr[0]<fence_size && curr[1]>=0 && curr[1]<n && visited[curr[0]][curr[1]]==0){

                        visited[curr[0]][curr[1]] = 1;
                        q.push_back({curr[0]-1, curr[1]});
                        q.push_back({curr[0]+1, curr[1]});
                        q.push_back({curr[0], curr[1]+1});
                        q.push_back({curr[0], curr[1]-1});
                    }
                }
            }
        }
    }
    cout << ans-1 << endl;
}