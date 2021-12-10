#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> arr(n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
    }
    vector<bool>visited(n+1, 0);
    vector<long long> regionId(n+1, -1);
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        if (!visited[i] && !visited[arr[i]]){
            long long curr = i;
            while (!visited[curr]){
                visited[curr] = 1;
                //regionId[curr] = ans;
                curr = arr[curr];
            }
            ans++;
        }
    }
    cout << ans << endl;
}