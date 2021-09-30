#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr (n);
    map <long long, vector <long long>> d;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
        if (d.count(arr[i])){
            d[arr[i]][i%2]++;
        }
        else{
            d[arr[i]] = {0, 0};
            d[arr[i]][i%2]++;
        }
    }
    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    //*To get to the final location, I will need to check how many times it flips. 
    //*Even if I don't go in shortest distance, result will be the same. 
    //!I see. The trick is that there can be duplicates. 
    //*Doesn't matter since only 2 types. 

    for (long long i=0;i<n;i++){
        if (d[sorted[i]][i%2]==0){
            cout << "NO" << endl;
            return;
        }
        else{
            d[sorted[i]][i%2]--;
        }
    }
    cout << "YES" << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}