#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    set <int> hashset;
    for (long long i=0;i<5;i++){
        hashset.insert((int) s[i]);
    }
    for (long long i=0;i<26;i++){
        if (hashset.count(97+i)==0){
            cout << (char) (97+i) << endl;
            break;
        }
    }
}