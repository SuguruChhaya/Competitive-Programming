#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    map<long long, map<long long, set<long long>>> d;
    
    set<long long> num1;
    for (long long i=0;i<m;i++){
        char c;
        long long a, b;
        cin >> c >> a >> b;
        vector<long long> temp = {a, b};
        sort(temp.begin(), temp.end());

        if (d[temp[0]].count(temp[1]) && !d[temp[0]][temp[1]].count(c)){
            cout << 0 << endl;
            return 0;
        }
        else{
            //!Reason to insert if the key didn't exist in the first place. 
            d[temp[0]][temp[1]].insert(c);
            num1.insert(temp[1]);
        }
    }
    string ans = "1";
    for (long long i=0;i<n-num1.size();i++){
        ans.push_back('0');
    }
    cout << ans << endl;
}