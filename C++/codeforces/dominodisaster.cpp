#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    //*Just map it.
    string result;
    map <char, char> d = {{'U', 'D'}, {'D', 'U'}, {'L', 'L'}, {'R', 'R'}};
    string s;
    cin >> s;
    for (long long i=0;i<n;i++){
        result.push_back(d[s[i]]);
    }
    cout << result << endl;
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}