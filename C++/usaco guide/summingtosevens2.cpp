#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    long long n;cin >>n;
    vector <long long> first, last;
    for (long long i=0;i<7;i++){
        first.push_back(9999999999);
        last.push_back(0);
    }

    //*We initialize the first to be 0 so that if the last is 0, then that counts from all the way from beginning. 
    first[0] = 0;
    long long curr = 0;
    for (long long i=1;i<=n;i++){
        long long temp; 
        cin >> temp;
        curr+=temp;
        curr%=7;
        first[curr] = min(first[curr], i);
        last[curr] = i;
    }
    long long result = 0;
    for (long long i=0;i<7;i++){
        if (first[i] < n){
            result =max(result, last[i] - first[i]);
        }
    }
    /*
    for (auto e:first){
        cout << e << endl;
    }
    for (auto e:last){
        cout << e << endl;
    }
    */

    cout << result << endl;
}