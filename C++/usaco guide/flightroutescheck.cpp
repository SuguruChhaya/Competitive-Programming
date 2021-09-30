#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> arr;
vector <bool> visited;
long long n, m;
void dfs(long long i){
    if (visited[i]==0){
        visited[i]=1;
        for (long long j=1;j<=n;j++){
            if (arr[i][j]==1){
                dfs(j);
            }
        }
    }
}
int main(){
    //freopen("flightroutecheck.in", "r", stdin);
    cin >> n >> m;
    arr.resize(n+1, vector <long long> (n+1, 0));
    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        arr[a][b]=1;
    }
    //?Probably some kind of memory error with too many elements. 
    for (long long i=1;i<=n;i++){
        visited.clear();
        visited.resize(n+1, 0);
        //dfs(i);
        //*If the recusion has limits, just make it iterative.
        deque <long long> q = {i};
        while (!q.empty()){
            long long curr = q[q.size()-1];
            q.pop_back();
            //cout << curr << endl;
            if (visited[curr]==0){
                visited[curr]=1;
                for (long long j=1;j<=n;j++){
                    if (arr[curr][j]==1){
                        q.push_back(j);
                    }
                }
            }
        }

        for (long long j=1;j<=n;j++){
            if (visited[j]==0){
                cout << "NO" << endl;
                cout << i << " " << j << endl;
                return 0;
            }
        }

    }
    
    //!Just because I can reach everywhere from one index doesn't mean. 
    //*Because one-way, need to check from every. 
    //!I don't have to loop through everything. 

    cout << "YES" << endl;
}