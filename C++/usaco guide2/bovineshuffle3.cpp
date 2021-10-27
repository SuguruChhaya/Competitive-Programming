#include <bits/stdc++.h>
using namespace std;
bool ok;
//vector <bool> checked;
vector <bool> visited;
vector <vector <long long>> opposite;
vector <bool> ans_arr;
/*
void trace_back(long long i){
    if (!ok && !visited[i]){
        visited[i] = 1;
        for (auto e:opposite[i]){
            trace_back(e);
        }
    }
    else{
        ok = true;
    }
}
*/
bool trace_back(long long i){
    if (!visited[i]){
        visited[i]=1;
        for (auto e:opposite[i]){
            bool temp = trace_back(e);
            if (temp){
                ans_arr[i] = 1;
                break;
            }
        }
        return ans_arr[i];
    }
    else{
        return true;
    }
    
}
//!Want to use tail recursion in a smart way. 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    long long n;
    cin >> n;
    opposite.resize(n+1);
    for (long long i=1;i<=n;i++){
        long long temp;
        cin >> temp;
        opposite[temp].push_back(i);
    }
    //checked.resize(n+1, 0);
    long long ans = 0;
    visited.resize(n+1, 0);
    ans_arr.resize(n+1, 0);
    for (long long i=1;i<=n&&!visited[i];i++){

        //ok = false;
        trace_back(i);

    }
    //ong long ans = 0;
    for (long long i=1;i<=n;i++){
        ans+=ans_arr[i];
    }
    cout << ans << endl;
}