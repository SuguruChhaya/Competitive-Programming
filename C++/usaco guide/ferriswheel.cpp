#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //*Start with the largest seems like a good idea. 
    //!Just try the greed method. 
    long long ans=0, l=0, r=n-1;

    while (l<=r){
        if (arr[l]+arr[r]<=x){
            ans++;
            l++;
            r--;
        }
        else{
            //*Only choose larger. 
            ans++;
            r--;
        }
    }
    cout << ans << endl;
}