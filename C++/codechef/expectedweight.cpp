#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long largest = 0, smallest = 0;
    for (long long i=1;i<=n;i++){
        largest += i*i;
    }
    for (long long i=1;i<=n;i++){
        smallest += i * (n+1-i);
    }
    //!Calculate arithmetic sum. 
    
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}