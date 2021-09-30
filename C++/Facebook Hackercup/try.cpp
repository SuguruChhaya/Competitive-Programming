#include <bits/stdc++.h>
using namespace std;

int main(){
    map <long long, vector <long long>> d;
    d[1].push_back(2);
    for (auto p:d){
        cout << p.first << " " << p.second.size() << endl;
    }
    map <long long, map<long long, bool>>e;
    e[0][1] = 0;
    for (auto p:e){
        for (auto k:p.second){
            cout << k.first << " " << k.second << endl;
        }
    }
}