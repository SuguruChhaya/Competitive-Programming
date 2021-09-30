#include <bits/stdc++.h>
using namespace std;
long long n, m, first_zero=1;
vector <vector <long long>> arr;
vector <long long> closed, copy_arr;

void dfs(long long i){
    if (copy_arr[i]==0){
        copy_arr[i]=1;
        for (auto e:arr[i]){
            dfs(e);
        }
    }
}

void check(){
    //cout << copy_arr.size() << endl;
    copy_arr = closed;
    while (first_zero <= n && copy_arr[first_zero]!=0){
        first_zero++;
    }
    
    dfs(first_zero);
    //*<=n
    for (long long i=1;i<=n;i++){
        if (copy_arr[i]==0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl; 
}
int main(){ 
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    arr.resize(n+1, vector <long long>());
    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    closed.resize(n+1, 0);
    closed[0] = -1;
    for (long long i=0;i<n;i++){
        check();
        long long temp;
        cin >> temp;
        closed[temp]=1;
    }
}