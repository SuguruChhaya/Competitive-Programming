#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> arr;
string s = " ";
vector<bool> visited;
vector<long long> numH, numG;
void dfs(long long curr, long long h, long long g){

    if (!visited[curr]){
        visited[curr] = 1;
        g+=s[curr]=='G';
        h+=s[curr]=='H';
        numH[curr] = h;
        numG[curr] = g;
        for (auto e:arr[curr]){
            dfs(e, h, g);
        }
    }
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    visited.resize(n+1, 0);
    numH.resize(n+1, 0);
    numG.resize(n+1, 0);
    string temp;
    cin >> temp;
    s += temp;
    arr.resize(n+1);
    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    for (long long i=0;i<m;i++){
        long long a, b;
        char c;
        cin >> a >> b >> c;
        if (c=='H'){
            cout << (numH[a] != numH[b]);
        }
        else{
            cout << (numG[a] != numG[b]);
        }
    }
}