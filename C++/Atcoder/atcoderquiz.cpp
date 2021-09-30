#include <bits/stdc++.h>
using namespace std;

int main(){
    set <string> s = {"ABC", "ARC", "AGC", "AHC"};
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s.erase(s1);
    s.erase(s2);
    s.erase(s3);
    cout << *s.begin() << endl;
}