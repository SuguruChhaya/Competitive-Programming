#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<bool> own(2*n+1, 1);
    vector<long long> arr;
    for (long long i=0;i<n;i++){
        long long a;
        cin >> a;
        own[a] = 0;
        arr.push_back(a);
    }
    set <long long> ownSet;
    for (long long i=1;i<=2*n;i++){
        if (own[i]){
            ownSet.insert(i);
        }
    }
    long long ans = 0;
    for (auto e:arr){
        auto it = ownSet.upper_bound(e);
        if (it!=ownSet.end()){
            ans++;
            ownSet.erase(it);
        }
    }

    cout << ans << endl;
}