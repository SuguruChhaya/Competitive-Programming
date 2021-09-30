#include <bits/stdc++.h>
using namespace std;

bool i_wins(vector <vector <long long>> arr, long long winner, long long i){
    long long i_wins = 0;
    for (long long j=0;j<5;j++){
        //*Should count for when same values are passed in. 
        if (arr[i][j] < arr[winner][j]){
            i_wins++;
        }
        if (i_wins>=3){
            return true;
        }
    }
    return false;
}
void solve(){
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long> (5));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    long long winner = 0;
    for (long long i=0;i<n;i++){
        if (i_wins(arr, winner, i)){
            winner = i;
        }
    }

    bool real_winner = true;
    for (long long i=0;i<n;i++){
        if (i_wins(arr, winner, i)){
            real_winner = false;
            break;
        }
    }
    if (real_winner){
        cout << winner + 1 << endl;
    }
    else{
        cout << -1 << endl;
    }

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}