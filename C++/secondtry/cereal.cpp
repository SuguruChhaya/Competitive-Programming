#include <bits/stdc++.h>
using namespace std;
template class map<long long, long long>;
int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out","w", stdout);
    long long n, m;
    cin >> n >> m;
    map<long long, long long> occupying;
    vector<vector<long long>> arr(n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<long long> ans(n, 0);
    //long long temp = 0;
    for (long long i=n-1;i>=0;i--){
        long long j=i, want = arr[j][0];
        while (1){
            //*If an earlier cow already occupies, break
            if (occupying.count(want) && occupying[want]<j){
                break;
            }

            //*This loop is guaranteed to end in 2 runs. Is that correct?
            else if (want==arr[j][1]){
                ans[i]++;
                occupying[want] = j;
                break;
            }
            else if (!occupying.count(want)){
                occupying[want] = j;
                ans[i]++;
                break;
            }
            else{
                long long stealFrom = occupying[want];
                occupying[want] = j;
                j = stealFrom;
                want = arr[j][1];
                ans[i]++;
            }
        }
    }
    for (long long i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}