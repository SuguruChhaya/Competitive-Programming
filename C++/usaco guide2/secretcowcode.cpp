#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    string s;
    long long n;
    cin >> s >> n;
    long long quotient = n / s.size();
    long long remainder = n % s.size();
    long long startswith = quotient % s.size();
    long long movesTo = (startswith+remainder-1) % s.size();
    cout << s[movesTo] << endl;
}