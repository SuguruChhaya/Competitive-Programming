#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, n;
    cin >> n >> x;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long long ans = 0, currMins=0,curr=0;
    while (curr < n && currMins<=x){
        currMins+=arr[curr];
        ans++;
        curr++;
    }
    //!We don't always have to decrease ans if we aren't over. 
    if (currMins>x){
        ans--;
    }
    cout << ans << endl;
}