#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("helpcross.in", "r", stdin);
    //freopen("helpcross.out", "w", stdout);
    long long c, n;
    cin >> c >> n;
    vector <long long> chickens (c);
    vector <vector<long long>> reversedCows(n, vector<long long>(2));

    for (long long i=0;i<c;i++){
        cin >> chickens[i];
    }
    for (long long i=0;i<n;i++){
        cin >> reversedCows[i][1] >> reversedCows[i][0];
    }
    sort(reversedCows.begin(), reversedCows.end());
    sort(chickens.begin(), chickens.end());

    long long currChicken = 0, currCow = 0, ans=0;
    while (currChicken<c && currCow<n){
        if (reversedCows[currCow][1] <= chickens[currChicken] && chickens[currChicken] <= reversedCows[currCow][0]){
            ans++;
            currChicken++;
            currCow++;
        }
        else if (reversedCows[currCow][0]<chickens[currChicken]){
            currCow++;
        }
        else{
            currChicken++;
        }
    }
    cout << ans << endl;
    //!Sorting 2 pointer strategy doesn't work so 
}