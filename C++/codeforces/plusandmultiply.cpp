#include <bits/stdc++.h>
using namespace std;
bool result = false;

void recursive(long long n, long long a, long long b, set <long long> used){
    if (n==1 || result){
        result = true;
    }
    //!This condition is somehow wrong. 
    else if (!used.count(n) && n>=1){
        //cout << n << endl;
        auto copy = used;
        copy.insert(n);
        long long divide = n/a;
        if (a * divide == n){
            recursive(n/a, a, b, copy);
        }
        recursive(n-b, a, b, copy);
    }
}
void solve(){
    long long n, a, b;
    cin >> n >> a >> b; 
    result = false;
    set <long long> used;
    recursive(n, a, b, used);
    if (result){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}