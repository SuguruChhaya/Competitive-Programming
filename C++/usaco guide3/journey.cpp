#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> arr;
double ans = 0;
vector<bool> visited;
void dfs(long long curr, double num, double prob){
    visited[curr]= 1;
    //bool ok = 0;
    vector<long long> temp;
    for (auto e:arr[curr]){
        
        if (!visited[e]){
            //ok = 1;
            //*Find the number of ones it COULD go to,
            //dfs(e, num+1, prob*(1.0/arr[curr].size()));
            temp.push_back(e);
        }
    }
    if (temp.size()==0){
        ans += (num*prob);
    }
    else{
        for (auto e:temp){
            dfs(e, num+1, prob*(1.0/temp.size()));
        }
        
    }
}

int main(){
    long long n;
    cin >> n;
    arr.resize(n+1);
    visited.resize(n+1, 0);
    for (long long i=0;i<n-1;i++){
        long long a,b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, 0, 1);
    cout << ans << endl;
}