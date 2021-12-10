#include <bits/stdc++.h>
using namespace std;

long long firstZero(vector <long long>arr){
    for (long long i=0;i<arr.size();i++){
        if (arr[i]==0){
            return i;
        }
    }
    return -1;
}

int main(){
    long long n;
    cin >> n;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long i=firstZero(arr);
    long long ans = 0;
    //?Should I really be looking from the front? Because same cows may move multiple times??
    
    while (i!=-1){
        long long dist = 0;
        long long j=i;
        while (arr[j]==0){
            j--;
            dist++;
            if (j==-1){
                j=n-1;
            }
        }
        ans+=pow(dist)
    }
}