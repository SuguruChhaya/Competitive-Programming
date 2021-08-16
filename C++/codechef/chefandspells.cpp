#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long a, b, c;
        cin >> a >> b >> c;
        long long temp = max(a+b, a+c);
        long long result = max(temp, b+c);
        cout << result << "\n";
    }
}