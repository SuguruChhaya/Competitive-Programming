#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector <long long> desired (n), actual(m);
    for (long long i=0;i<n;i++){
        cin >> desired[i];
    }
    for (long long i=0;i<m;i++){
        cin >> actual[i];
    }
    //*I think I can pretty much sort the 2 apartments and use pointers.
    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());
    long long i=0, j=0, ans=0;

    while (i<n && j<m){
        if (abs(desired[i]-actual[j])<=k){
            //*Use up both. 
            i++;
            j++;
            ans++;
        }
        //*The desired size was too small. 
        else if (desired[i]<actual[j]){
            i++;
        }
        else if (desired[i]>actual[j]){
            j++;
        }
    }
    cout << ans << endl;
}