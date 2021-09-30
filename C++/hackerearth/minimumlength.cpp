#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long l = 1, r=100000, temp;
    while (l<=r){
        long long mid = (l+r) / 2;
        long long curr = 2*mid + pow(mid, 2);
        if (curr==n){
            cout << mid*2 << endl;
            return;
        }
        else if (curr>n){
            temp = mid;
            r = mid-1;
        }
        else if (curr<n){
            l = mid+1;
        }
    }
    long long a=temp, b = temp;
    while ((a+b)+(a*b)>=n){
        a--;
    }
    a++;
    cout << a+b << endl;
    return;
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}