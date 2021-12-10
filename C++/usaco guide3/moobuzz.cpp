#include <bits/stdc++.h>
using namespace std;

long long find(long long mid){
    return mid/3+mid/5-mid/15;
}

int main(){
    //freopen("moobuzz.in", "r", stdin);
    //freopen("moobuzz.out", "w", stdout);
    long long n;
    cin >> n;
    long long l=0, r = 1000000000000000, ans;
    while (l<=r){
        long long mid = (l+r) / 2, temp = find(mid);
        //!Should be the first number that satisfies the conditions. 
        if (temp==n-1 && mid%3!=0 && mid%5!=0 && mid%15!=0){
            ans = mid;
            r = mid-1;
        }
        else if (temp<=n-1){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}