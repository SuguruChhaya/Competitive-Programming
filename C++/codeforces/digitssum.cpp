#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        //*Convert to string. 
        long long n;
        cin >> n;
        if (n==1){
            cout << 0 << endl;
        }
        else if (n < 10){
            cout << 1 << endl;
        }
        else{
            string s = to_string(n);
            cout << s.substr(0, s.size()-1) << endl;
        }
    }
}