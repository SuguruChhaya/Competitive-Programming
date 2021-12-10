#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
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
    //!No issues with seg errors so want to ignore ones with them, 
    long long currBoot = 0, currTile = 0;
    bool segfault = 0;
    while (currTile<n-1){
        bool ok = 0;
        for (long long i=boots[currBoot][1];i>0;i--){
            if (currTile+i<n && snow[currTile+i]<=boots[currBoot][0]){
                ok = 1;
                currTile += i;
                break;
            }
        }
        if (!ok){
            currBoot++;
            while (currBoot < b && boots[currBoot][0]<snow[currTile]){
                currBoot++;
            }
            
            if (currBoot==b){
                segfault = 1;
                break;
            }
        }
    }
    if (segfault){
        cout << -1 << endl;
    }
    else{
        cout << currBoot << endl;
    }
    
    
}