#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        map <long long, long long> d;
        for (long long i=0;i<n;i++){
            long long temp;
            cin >> temp;
            d[temp]++;
        }
        long long curr = 0, ans = 0;
        for (auto p:d){
            curr+=p.second;
            if (curr>n-curr){
                ans+=p.second;
            }
        }
        cout << ans << endl;
    }
}