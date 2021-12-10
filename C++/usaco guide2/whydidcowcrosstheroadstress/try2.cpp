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
    long long currChicken = 0, ans=0;
    for (long long i=0;i<n;i++){
        //!Cannot expect to be able to pair up with every single cow. 
        //!Check if for the starting point
        while (currChicken < c && chickens[currChicken] < reversedCows[i][1]){
            currChicken++;
        }
        if (currChicken!=c && chickens[currChicken]<=reversedCows[i][0]){
            ans++;
            currChicken++;

        }
    }
    cout << ans << endl;
}