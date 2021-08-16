#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if (n<=125){
        cout << 4 << endl;
    }
    else if (n <=211){
        cout << 6 << endl;
    }
    else{
        cout << 8 << endl;
    }
}