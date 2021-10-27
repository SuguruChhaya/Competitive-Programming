#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> curr(n+1);
    vector <long long> arr (n+1);
    vector <bool> ans_arr(n+1, 1);

    for (long long i=1;i<=n;i++){
        cin >> arr[i];
        curr[i].push_back(arr[i]);
    }
    for (long long count = 0;count<n;count++){
        vector <vector <long long>> next (n+1);
        for (long long i=1;i<=n;i++){
            for (auto e:curr[i]){
                next[arr[i]].push_back(e);
            }
        }
        for (long long i=1;i<=n;i++){
            if (next[i].size()==0){
                ans_arr[i] = 0;
            }
        }
        curr = next;
    }
    long long ans=0;
    for (long long i=1;i<=n;i++){
        ans += ans_arr[i];
    }
    cout << ans << endl;
}