#include <bits/stdc++.h>
using namespace std;

int main(){
    long long l, q;
    cin >> l >> q;
    set <long long> s = {0, l};
    while (q--){
        long long c, x;
        cin >> c >> x;
        if (c==1){
            s.insert(x);
        }
        else{
            //*Have to perform binary search on the set. 
            //!Use set.lower_bound or something. 
            auto larger = s.upper_bound(x);
            auto smaller = larger;
            smaller--;

            cout << *larger - *smaller << endl;
        }
    }
}