#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, d, h;
        cin >> n >> d >> h;
        long long curr = 0;
        bool red = false;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            if (temp==0){
                long long zero = 0;
                curr = max(zero, curr-d);
            }
            else{
                curr += temp;
            }
            if (curr > h){
                cout << "YES" << "\n";
                red = true;
                break;
            }
            
        }
        if (red==false){
            cout << "NO" << "\n";
        }
    }
}