#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long a,b,c;
    cin >> a >> b >> c;
    long long numbetween = abs(a-b)-1;
    long long numtoone = min(a, b) - 1;
    bool found = false;
    long long ans;
    if (numtoone <=numbetween){
        long long largest = max(a, b) + numbetween - numtoone;
        //*Now I can check whether the largest is even. 
        if (largest % 2==0){
            if (c <= largest){
                
                if (c+largest/2<=largest){
                    ans = c+largest/2;
                }
                else{
                    ans = c-largest/2;
                }
                found = true;
            }
        }
    }
    if (found){
        cout << ans << endl;
    }
    else{
        cout << -1<< endl;
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}