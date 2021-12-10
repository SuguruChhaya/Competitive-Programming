#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    long long n, m, r;
    cin >> n >> m >> r;
    vector <long long> cows(n);
    for (long long i=0;i<n;i++){
        cin >> cows[i];
    }
    vector<vector<long long>> buyers (m, vector<long long>(2));
    for (long long i=0;i<m;i++){
        cin >> buyers[i][1] >> buyers[i][0];
    }
    vector<long long> rentals(r);
    for (long long i=0;i<r;i++){
        cin >> rentals[i];
    }
    //vector<long long> gallonsSold(m, 0);
    sort(cows.begin(), cows.end());
    sort(buyers.begin(), buyers.end());
    sort(rentals.begin(), rentals.end());
    long long ans = 0;
    for (long long i=0;i<=r;i++){
        long long currTotal = 0;
        for (long long j=0;j<i;j++){
            currTotal+=rentals[r-1-j];
        }
        long long milkAmount = 0;
        for (long long j=i;j<n;j++){
            milkAmount+=cows[j];
        }
        long long currBuyer = m-1;
        while (currBuyer>=0 && milkAmount>0){
            long long gallonsBought = min(milkAmount, buyers[currBuyer][1]);
            milkAmount -= gallonsBought;
            currTotal+=gallonsBought * buyers[currBuyer][0];
            if (gallonsBought==buyers[currBuyer][1]){
                currBuyer--;
            }
        }
        ans = max(ans, currTotal);
    }
    cout << ans << endl;
}