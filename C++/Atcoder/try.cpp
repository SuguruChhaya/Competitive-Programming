#include <bits/stdc++.h>
using namespace std;

int main(){
    //!upper_bound: purely greater
    set <long long> s = {1, 3};
    long long a = *s.upper_bound(2);
    cout << a << endl;

    deque <long long> q;
    q.push_back(3);
    q.push_back(2);
    sort(q.begin(), q.end());
    cout << q[0] << endl;
}