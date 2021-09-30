#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("convention.out", "w", stdout);
    long long n, m, c;
    cin >> n >> m >> c;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //!Last cow on it doesn't mean that the entire bus must be full. 
    //*Then I need to check the dividing points. 
    
    long long ans = 0;
    for (long long i=0;i<=n;i++){
        if ((i+1)%c==0){
            ans = max(ans, arr[i]-arr[i-c+1]);
        }
    }
    cout << ans << endl;
}