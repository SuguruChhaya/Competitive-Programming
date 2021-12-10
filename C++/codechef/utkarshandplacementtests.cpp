#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<char> order;
    for (int i=0;i<3;i++){
        char c;
        cin >> c;
        order.push_back(c);
    }
    set<char>s;
    for (int i=0;i<2;i++){
        char c;
        cin >> c;
        s.insert(c);
    }
    for (auto e:order){
        if (s.count(e)){
            cout << e << endl;
            return;
        }
    }

    
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}