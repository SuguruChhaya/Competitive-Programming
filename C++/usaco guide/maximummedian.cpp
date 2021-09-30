#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long zero = 0;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //*the largest possible median value will be the largest value +k. 
    long long l = arr[n/2], r = arr[n-1]+k, last_valid=arr[n/2];
    while (l<=r){
        long long mid = (l+r)/2, need = 0;
        for (long long i=n/2;i<n;i++){
            need += max(zero, mid-arr[i]);
        }
        if (need<=k){
            last_valid = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << last_valid << endl;
}