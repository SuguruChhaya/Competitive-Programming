#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    long long n, b;
    cin >> n >> b;
    vector<long long> snow(n);
    for (long long i=0;i<n;i++){
        cin >> snow[i];
    }
    vector<vector<long long>> boots(b, vector<long long>(2));
    for (long long i=0;i<b;i++){
        cin >> boots[i][0] >> boots[i][1];
    }
    //!Don't go to the furthest. Rather, I can mark everywhere that I can go to and then go from there. 
    
}