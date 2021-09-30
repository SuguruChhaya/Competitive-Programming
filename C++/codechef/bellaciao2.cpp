#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long D, d, P, Q;
        cin >> D >> d >> P >> Q;
        long long increase_remainder = D % d, increase_blocks = D/d;
        long long largest = P+((increase_blocks-1)*Q);
        long long result = ((P+largest) / 2) * d * increase_blocks;
        result+=(largest+Q) * increase_remainder;
        cout << result << endl; 
    }
}