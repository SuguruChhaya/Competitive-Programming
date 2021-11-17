#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <vector <bool>> arr(3000, vector<bool>(3000, 0));
    long long n;
    cin >> n;
    vector <vector <long long>> allCows;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        arr[x+1000][y+1000]=1;
        allCows.push_back({x, y});
        //vector<vector<long long>> additional;
        queue<vector<long long>> q;
        /*
        q.push({x+1000, y+1000});
        q.push({x-1+1000, y+1000});
        q.push({x+1+1000, y+1000});
        q.push({x+1000, y-1+1000});
        q.push({x+1000, y+1+1000});
        for (auto e:carryOver){
            q.push(e);
        }
        */
        //!TLE approach but DFS all cows every run. 
        for (auto e:allCows){
            q.push({e[0]+1000, e[1]+1000});
        }
        vector <vector <long long>> changed;
        //bool firstTime = true;
        while (!q.empty()){
            auto curr = q.front();
            q.pop();
            vector <vector<long long>> temp;
            if (!arr[curr[0]-1][curr[1]]){
                temp.push_back({curr[0]-1, curr[1]});
            }
            if (!arr[curr[0]+1][curr[1]]){
                temp.push_back({curr[0]+1, curr[1]});
            }
            if (!arr[curr[0]][curr[1]-1]){
                temp.push_back({curr[0], curr[1]-1});
            }
            if (!arr[curr[0]][curr[1]+1]){
                temp.push_back({curr[0], curr[1]+1});
            }
            if (temp.size()==1){
                long long a = temp[0][0], b = temp[0][1];
                arr[a][b] = 1;
                //firstTime = false;
                changed.push_back(temp[0]);
                q.push({a-1, b});
                q.push({a+1, b});
                q.push({a, b-1});
                q.push({a, b+1});
            }
            //!Need to consider the issues that carry over. 
        }
        cout << changed.size() << endl;
        for (auto p:changed){
            arr[p[0]][p[1]] = 0;
        }
    }
}