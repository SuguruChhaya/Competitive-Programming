#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    //*I see. The brute force way would be to try starting from every possible and seeing upto where I can go to. 
    //*But I can easily see how I can use 2 pointer. 
    ll n, t;
    cin >> n >> t;
    vector <ll> arr (n);
    for (ll i=0;i<n;i++){
        cin >> arr[i];
    }
    ll l=0, r=0, totalMin=0, result=0;
    while (l<n && r<n){
        cout << l << " " << r << " " << totalMin  << endl;
        if (totalMin+arr[r]<=t){
            totalMin+=arr[r];

            result=max(result, r-l+1);
            r++;
        }
        else{
            totalMin-=arr[l];
            l++;
            r = max(r, l);
        }
    }
    cout << result << endl;
}