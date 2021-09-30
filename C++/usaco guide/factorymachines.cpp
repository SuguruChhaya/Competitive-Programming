#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, t;
    cin >> n >> t;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //
    //*Longest amount of time is t / smallest 
    long long l=0, r = arr[0] * t, ans;
    while (l<=r){
        long long mid = (l+r) / 2;
        //*Store the total # of machines able to make. 
        long long currMachines = 0;
        for (long long i=0;i<n && arr[i]<=mid;i++){
            currMachines += mid/arr[i];
        }
        if (currMachines>=t){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}