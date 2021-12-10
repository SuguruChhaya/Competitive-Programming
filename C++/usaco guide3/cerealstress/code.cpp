#include <bits/stdc++.h>
using namespace std;
template class map<long long, long long>;
int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out","w", stdout);
    long long n, m;
    cin >> n >> m;
    map<long long, long long> occupying;
    vector<vector<long long>> arr(n, vector<long long>(2, 0));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<long long> ans(n+1, 0);
    //long long temp = 0;
    for (long long i=n-1;i>=0;i--){
        long long j=i, want = arr[j][0];
        ans[i] = ans[i+1];
        while (1){
            //*If an earlier cow already occupies, break
            if (occupying.count(want) && occupying[want]<j){
                break;
            }

            //*This loop is guaranteed to end in 2 runs. Is that correct?
            //!Just because it is its second choice doesn't mean we should exploring. 
            //*Only if there is nothing occupying next. 
            else if (want==arr[j][1] && !occupying.count(want)){
                if (!occupying.count(want)){
                    ans[i]++;
                }
                occupying[want] = j;
                break;
            }
            else if (!occupying.count(want)){
                occupying[want] = j;
                ans[i]++;
                break;
            }
            else{
                //!Num cows??
                long long stealFrom = occupying[want];
                occupying[want] = j;
                j = stealFrom;
                want = arr[j][1];
                //ans[i]++;
            }
        }
    }
    for (long long i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}