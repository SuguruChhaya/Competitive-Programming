#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    string s;cin >> s;
    vector <long long> prefix (n+1, 0);
    for (long long i=1;i<=n;i++){
        
        string temp_string;
        temp_string.push_back(s[i-1]);
        long long temp = stoi(temp_string);
        prefix[i]=prefix[i-1] + temp;
    }
    map <long long, long long> d;
    for (long long i=0;i<=n;i++){
        d[prefix[i]-i]++;
    }
    long long result =0;
    for (auto p:d){
        result += (p.second) * (p.second-1) / 2;
    }
    cout << result << endl;
}
int main(){
    //*I think I finally got it so finish this problem once and for all. 
    long long t;cin >> t;
    while (t--){
        solve();
    }
}