#include <bits/stdc++.h>
using namespace std;
map <long long, set<long long>> s, d;
vector<long long> visited;
bool ok = true;
void visit(long long i, long long val){
    visited[i] = val;
    for (auto e:s[i]){
        //*Should be the same value. 
        if (visited[e]==0){
            visit(e, val);
        }
        else{
            if (visited[e]!=visited[i]){
                ok = false;
            }
        }
    }
    for (auto e:d[i]){
        if (visited[e]==0){
            visit(e, 3-val);
        }
        else{
            if (visited[e]==visited[i]){
                ok = false;
            }
        }
    }
}

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    visited.resize(n+1, 0);
    for (long long i=0;i<m;i++){
        char c;
        long long a, b;
        cin >> c >> a >> b;
        if (c=='S'){
            s[a].insert(b);
            s[b].insert(a);
        }
        else{
            d[a].insert(b);
            d[b].insert(a);
        }
    }
    long long num = 0;
    for (long long i=1;i<=n;i++){
        if (visited[i]==0){
            visit(i, 1);
            num++;
        }
    }
    if (!ok){
        cout << 0 << endl;
    }
    else{
        string ans = "1";
        for (long long i=0;i<num;i++){
            ans.push_back('0');
        }
        cout << ans << endl;
    }
}