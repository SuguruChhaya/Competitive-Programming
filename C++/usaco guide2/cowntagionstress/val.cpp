#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> arr;
vector <bool> visited;

void recursive(long long i){
    //cout << i << endl;
    if (!visited[i]){
        visited[i] = 1;
        for (auto e:arr[i]){
            recursive(e);
        }
    }

}

int main(){
    freopen("input_file", "r", stdin);
    //*Basically program to check whether all the components are connected. 
    //*Just do a simple DFS. 
    long long n;
    cin >> n;
    arr.resize(n+1);
    visited.resize(n+1, 0);
    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    recursive(1);

    for (long long i=1;i<=n;i++){
        if (!visited[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}