#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    long long c, n;
    cin >> c >> n;
    vector<long long> chickens(c);
    vector <vector <long long>> cows(n, vector<long long>(2));
    for (long long i=0;i<c;i++){
        cin >> chickens[i];
    }
    for (long long i=0;i<n;i++){
        cin >> cows[i][1] >> cows[i][0];
    }
    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end());
    long long ans = 0;
    //long long currChicken= 0;
    vector <bool> used (c, 0);
    for (long long i=0;i<n;i++){
        long long currChicken = 0;
        while (currChicken < c && (chickens[currChicken]<cows[i][1] || used[currChicken])){
            currChicken++;
        }
        if (currChicken<c && chickens[currChicken]<=cows[i][0]){
            ans++;
            used[currChicken] = 1;
            //currChicken++;
        }
    }
    cout << ans << endl;
}