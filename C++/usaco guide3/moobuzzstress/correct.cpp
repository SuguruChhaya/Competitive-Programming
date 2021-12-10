#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("moobuzz.in", "r", stdin);
    //freopen("moobuzz.out", "w", stdout);
    long long n;
    cin >> n;
    long long currNumber=0, num=0;
    while (currNumber<n){
        num++;
        if (!(num%3==0 || num%5==0 || num%15==0)){
            currNumber++;
        }
        
    }
    cout << num << endl;
}