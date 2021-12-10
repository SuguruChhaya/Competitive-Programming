#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    string s;
    cin >> n >> q >> s;
    long long num = 0;
    for (long long i=0;i<=n-3;i++){
        if (s.substr(i, 3)=="abc"){
            num++;
        }
    }
    for (long long i=0;i<q;i++){
        long long pos;
        char c;
        cin >> pos >> c;
        long long prevNum =0;
        for (long long i=pos-3;i<pos;i++){
            if (i>=0 && i+2<n && s.substr(i, 3)=="abc"){
                prevNum++;
            }
        }
        s[pos-1] = c;
        long long newNum = 0;
        for (long long i=pos-3;i<pos;i++){
            if (i>=0 && i+2<n && s.substr(i, 3)=="abc"){
                newNum++;
            }
        }
        num += (newNum-prevNum);
        cout << num << endl;
    }

}