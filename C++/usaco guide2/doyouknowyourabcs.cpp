#include <bits/stdc++.h>
using namespace std;


//A, B, C, A+B+C
//A+B could be larger than C could not be
//
int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> arr(n);
        for (long long j=0;j<n;j++){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());

    }

}