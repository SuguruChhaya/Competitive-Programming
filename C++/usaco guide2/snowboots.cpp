#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("reststops.in", "r", stdin);
    //freopen("reststops.out", "w", stdout);
    long long n, b;
    cin >> n >> b;
    vector<long long> snow(n);
    for (long long i=0;i<n;i++){
        cin >> snow[i];
    }
    vector<vector<long long>> boots(b, vector<long long>(2));
    for (long long i=0;i<b;i++){
        cin >> boots[i][0] >> boots[i][1];
    }
    long long currBoot= 0, currTile = 0;
    while (currTile<n-1){
        while (currTile<n-1 && currBoot < b && snow[currTile+1]<=boots[currBoot][0]&&boots[currBoot][1]>0){
            currTile++;
            boots[currBoot][1]--;
        }
        if (currTile==n-1){
            break;
        }
        else{
            currBoot++;
        }
    }
    cout << currBoot << endl;
}