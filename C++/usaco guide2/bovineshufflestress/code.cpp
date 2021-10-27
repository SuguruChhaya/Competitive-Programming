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
bool trace_back(long long i, long long original){

    if (!visited[i]){
        visited[i]=1;
        for (auto e:opposite[i]){
            bool temp = trace_back(e, original);
            if (temp){
                ans_arr[i] = 1;
                break;
            }
        }
        return ans_arr[i];
    }
    else{
        //!Check whether the cycle involves the original. 
        return i==original;
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
    long long curr = 1;
    while (curr<=n){
        if (!visited[curr]){
            trace_back(curr, curr);
        }
        curr++;
    }

    //ong long ans = 0;
    for (long long i=1;i<=n;i++){
        ans+=ans_arr[i];
    }
    cout << ans << endl;
    //*It may be connected to a cycle but the actual position might not be involved in the cycle itself. 
}