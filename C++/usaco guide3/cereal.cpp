#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> arr(n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    set<long long> taken;
    for (long long i=0;i<n;i++){
        taken = {};
        long long ans = 0;
        for (long long j=i;j<n;j++){
            if (!taken.count(arr[j][0])){
                taken.insert(arr[j][0]);
                ans++;
            }
            else if (!taken.count(arr[j][1])){
                taken.insert(arr[j][1]);
                ans++;
            }
        }
        cout << ans << endl;
    }
}