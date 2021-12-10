#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("a", "w", stdout);
    long long n = 3;
    vector<string> ans;
    queue <tuple<long long, long long, string>> q;
    q.push({0, 0, ""});
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        if (get<0>(curr)==n&&get<1>(curr)==n){
            ans.push_back(get<2>(curr));
        }
        else if (get<0>(curr)+get<1>(curr)<2*n){
            auto next1 = curr;
            get<0>(next1)++;
            get<2>(next1).push_back('(');
            q.push(next1);
            if (get<0>(curr)>get<1>(curr)){
                auto next2 = curr;
                get<1>(next2)++;
                get<2>(next2).push_back(')');
                q.push(next2);
            }
        }
    }
    for (auto e:ans){
        cout << e << endl;
    }
}