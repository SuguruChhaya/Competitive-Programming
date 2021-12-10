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

    long long currCow = 0, ans = 0;
    for (long long i=0;i<c;i++){
        //cout << i << endl;
        //!I see, when we hit somewhere that doesn't exist we end up stopping...
        //!I think we should run loop while end is smaller. 
        if (i==1){
            cout << ""; 
        }
        while (currCow<n && reversedCows[currCow][0]<chickens[i]){
            currCow++;
        }
        //!Even if there is a cow with valid end-time, no good if start time doesn't match.     
        if (currCow!=n && reversedCows[currCow][1]<=chickens[i]){
            ans++;
            currCow++;
        }
    }
    cout << ans << endl;
}