#include <bits/stdc++.h>
using namespace std;

bool isConsecutive(vector<long long> arr, long long i, long long n){
    for (long long j=i+1;j<i+n;j++){
        if (arr[j]!=arr[j-1]+1){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("9.in", "r", stdin);
    //freopen("herding.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }   
    sort(arr.begin(), arr.end());
    long long minEmpty = 9999999999999;

    //!Don't have to do binary search if we keep 
    for (long long i=0;i<n;i++){
        long long maxi = arr[i]+n-1;
        long long l=i, r=n-1, lastValid = l;
        while (l<=r){
            long long mid = (l+r) /2;
            if (arr[mid]<=maxi){
                lastValid = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        long long temp = n-(lastValid-i+1);
        if (temp==1 && isConsecutive(arr, i, n-1)){
            //*All are consecutive and there is one outlier. 
            temp++;
        }
        minEmpty = min(minEmpty, temp);
        //maxEmpty = max(maxEmpty, n-(lastValid-i+1));
    }
    //?If there are so many gaps, will I only consider the largest?
    long long maxEmpty = 0;
    for (long long i=1;i<n;i++){
        maxEmpty = max(maxEmpty, arr[i]-arr[i-1]-1);
    }
    cout << minEmpty << endl << maxEmpty << endl;
}