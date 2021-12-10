#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    long long n;
    cin >> n;
    long long l = n, r = 100000000000000;
    while (l<=r){
        long long mid = (l+r) / 2, num = mid-(mid/3+mid/5-mid/15);
        if (num==n&&mid%3!=0&&mid%5!=0&&mid%15!=0){
            cout << mid << endl;
            return 0; 
        }
        else if (num<n){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
}