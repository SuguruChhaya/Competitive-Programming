//?My guess is that we are doing too much recursion. 
#include <bits/stdc++.h>
using namespace std;
map <long long, map<long long, long long>> d;
vector<vector<vector<long long>>> arr;
long long k, v, ans=0;
vector<bool> visited;
/*
long long dfs(long long i, long long j, long long prev, vector<vector<long long>> order){
    
    if (i==j){
        long long mini = 99999999999999;
        for (auto e:order){
            mini = min(mini, m[{e[0], e[1]}]);
        }
        return mini;
    }
    else{
        //!Only want to consider everything that was in the path. 
        //*Store in vector. Calculation comes later. 
        for (auto e:d[i]){
            if (e!=prev){
                //!Shouldn't be counting minimum for all because not all path. 
                //mini = min(m[{i, e}], mini);
                //mini = min(mini, dfs(e, j, i));
                auto nextOrder = order;
                nextOrder.push_back({i, e});
                long long temp = dfs(e, j, i, nextOrder);
                if (temp!=-1){
                    return temp;
                }
            }
        }
        return -1;
    }

}
*/
void dfs(long long curr, long long currMin){
    if (!visited[curr]){
        visited[curr] = 1;
        ans++;
        /*
        for (auto e:d[curr]){
            dfs(e.first, min(currMin, e.second));
        }
        */
        //!Any DFS vs BFS?
        for (auto e:arr[curr]){
            if (min(currMin, e[1])>=k){
                dfs(e[0], min(currMin, e[1]));
            }
            
        }
    }
}
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    long long n, q;
    cin >> n >> q;
    arr.resize(n+1);

    for (long long i=0;i<n-1;i++){
        long long p, q, r;
        cin >> p >> q >> r;
        //*I think the dictionary structure might not be best. 
        /*
        d[p][q] = r;
        d[q][p] = r;
        */
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    //*Honestly feel like I should just keep a DP arr. 
    
    for (long long i=0;i<q;i++){
        ans = 0;
        cin >> k >> v;
        visited = {};
        visited.resize(n+1, 0);
        dfs(v, 99999999999);
        //*Remove the one itself. 
        cout << ans-1 << endl;
    }
}