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
    long long ans = 0;
    for (long long i=0;i<n;i++){
        long long j=arr[i];
        //cout << own[j] << endl;
        while (j<2*n+1&&!own[j]){
            j++;
        }
        if (j<2*n+1){
            ans++;
            own[j] = 0;
        }
    }
    cout << ans << endl;
}