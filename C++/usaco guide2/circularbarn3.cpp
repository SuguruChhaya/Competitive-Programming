/*
Is it even OK for the value to become negative?
Adjust so that the lowest point matches 0 and start from the place after that so end at 1. 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <long long> arr(n, 0);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long sum = 0, lowest = 99999999, lowestIndex = -1;
    for (long long i=0;i<n;i++){
        sum+=arr[i]-1;
        if (sum<lowest){
            lowest = sum;
            lowestIndex = i;
        }
    }
    long long startIndex = lowestIndex+1;
    
    if (startIndex==n){
        startIndex = 0;
        //*Could there really be this case??
        //!Yes e.g. 2, 0 and 2, 1, 1, 0
    }
    rotate(arr.begin(), arr.begin()+startIndex, arr.begin()+n);

    
    long long ans = 0;
    //*Can keep an array for the number of cows that originated from ith index?
    long long ptr = 0;
    for (long long i=0;i<n;i++){
        while (arr[ptr]==0){
            ptr++;
        }
        arr[ptr]--;
        ans+=pow(i-ptr, 2);
    }
    
}