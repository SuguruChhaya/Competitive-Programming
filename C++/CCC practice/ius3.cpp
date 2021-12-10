#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long numFrictions = 0;
    char prev = 'U';
    for (long long i=0;i<2*n;i++){
        if (s[i]==prev){
            numFrictions++;
        }
        prev = s[i];
    }
    if (s[2*n-1]=='I'){
        numFrictions++;
    }
    cout << numFrictions / 2 << endl;
}