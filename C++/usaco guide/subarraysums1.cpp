#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long l=0, r=0, result = 0, currSum=arr[0];
    while (l<n && r <n){
        //cout << l << " " << r << currSum << endl;
        if (currSum==x){
            result++;
            //*How should I move from here?
            currSum-=arr[l];
            l++;
        }
        else if (currSum<x){
            r++;
            currSum+=arr[r];
        }
        else{
            currSum-=arr[l];
            l++;
            //*Couldn't this just leave l to be ahead?
            r = max(r, l);
        }
    }
    cout << result << endl;
}