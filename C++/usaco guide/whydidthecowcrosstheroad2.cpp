#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    //Almost all correct. 
    long long n, k, b;
    cin >> n >> k >> b;
    //*Opposite since we are adding. 
    vector <bool> arr(n+1, 0);
    for (long long i=0;i<b;i++){
        long long temp;cin >> temp;
        arr[temp] = 1;
    }
    //*Had to make sure to start at one. 
    //*Check the sorting solution too. 

    //!I get the prefix sum implementation too. 
    //*Check how many broken were there in the given range and use the min. 
    
    long long result = 999999999, left = 1, prev=0;
    while (left+k-1<=n){
        if (left==1){
            for (long long i=1;i<=k;i++){
                prev+=arr[i];
            }
        }
        else{
            prev-=arr[left-1];
            prev+=arr[left+k-1];
        }

        result = min(result, prev);
        left++;
    }

    cout << result << endl;
}