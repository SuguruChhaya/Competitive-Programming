#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("rental.in", "r", stdin);
    //freopen("rental.out", "w", stdout);
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
    vector<long long> gallonsSold(m, 0);
    sort(cows.begin(), cows.end());
    sort(buyers.begin(), buyers.end());
    sort(rentals.begin(), rentals.end());

    long long curr=-1, currBuyer = m-1, sum=0;
    for (auto e:cows){
        sum+=e;
    }
    curr=0;
    //*Want to buy from the top. 
    while (currBuyer>=0 && sum>0){
        long long amount = min(sum, buyers[currBuyer][1]);
        sum-=amount;
        curr+=buyers[currBuyer][0] * amount;
        //!Just realized how I cannot use amount for this. 
        //!The if-statement below will always return true so no point
        if (amount==buyers[currBuyer][1]){
            currBuyer--;
        }
        else{
            buyers[currBuyer][1] = amount;
        }
        
    }
    
    //!Want to make the MOST money!!
    long long ans = curr;
    //!Don't think we have to do min. 
    for (long long i=r-1;i>=0;i--){
        //!We really have to precompute this part otherwise we start subtracting from the second largest cow. 
        curr+=rentals[i];
        long long gallonsLossed = cows[r-1-i];
        while (currBuyer<m && gallonsLossed>0){
            long long amount = min(gallonsLossed, buyers[currBuyer][1]);
            gallonsLossed -= amount;
            curr -= amount * buyers[currBuyer][0];
            buyers[currBuyer][1] -= amount;

            if (buyers[currBuyer][1]==0){
                currBuyer++;
            }
        }
        
        ans = max(ans, curr);
    }
    cout << ans << endl;
}