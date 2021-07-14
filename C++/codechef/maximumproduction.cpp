#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long d, x, y, z;
        cin >> d >> x >> y >> z;

        long long result = 0;
        result = max(result, x*7);

        result = max(result, y*d + z*(7-d));

        cout << result << "\n";
    }
}