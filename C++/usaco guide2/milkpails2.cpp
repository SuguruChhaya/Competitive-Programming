#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    long long x, y, k, m, ans=999999999;
    cin >> x >> y >> k >> m;
    deque<vector<long long>> q;
    q.push_back({0, 0, 0});
    set <vector <long long>> s;
    while (!q.empty()){
        auto curr = q[0];
        q.pop_front();
        if (curr[2]<=k && !s.count({curr[0], curr[1]})){
            s.insert({curr[0], curr[1]});
            ans = min(ans, abs(m-(curr[0]+curr[1])));
            long long num1 = curr[0];
            long long num2 = curr[1];
            long long depth = curr[2];
            q.push_back({x, num2, depth+1});
            q.push_back({num1, y, depth+1});
            if (num1+num2<x){
                q.push_back({num1+num2, 0, depth+1});
            }
            else{
                q.push_back({x, num2-(x-num1), depth+1});
            }
            if (num1+num2<y){
                q.push_back({0, num1+num2, depth+1});
            }
            else{
                q.push_back({num1-(y-num2), y, depth+1});
            }
            q.push_back({0, num2, depth+1});
            q.push_back({num1, 0, depth+1});
        }
    }
    cout << ans << endl;
}