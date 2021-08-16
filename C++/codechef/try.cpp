#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main(){
    int a = 5;
    int b = 3;
    int c = a^b;
    cout << c;

    constexpr int p {2 * 2 * 3};
    constexpr int q {2 * 3 * 3};
    static_assert(2 * 3 == gcd(p, q));
}