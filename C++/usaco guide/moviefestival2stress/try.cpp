#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset <long long> m;
    m.insert(0);
    m.insert(0);
    m.insert(1);
    auto it1 = m.upper_bound(0);
    auto it2 = m.lower_bound(0);
    //!Go after val. 
    cout << *it1 << endl;
    //!Doesn't
    it1++;
    cout << *it1 << endl;
    it2++;
    cout << *it2 << endl;
}