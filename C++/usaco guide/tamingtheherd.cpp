#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
Notice that if the counter is a positive number i on some day, then the counter must be i−1 on the previous day. So we can sweep from the last day backwards in time, applying this rule to fill in missing entries. If we try to fill in an entry which was not missing, then either nothing happens (if we try to fill in some number n, and the entry is already n), or we get a contradiction (if we try to fill in a number n, but the entry contains a different nonnegative number).

The first entry in the log is a special case, since Farmer John already knows the cows broke out on that day. So if it is a missing entry, we can set it to 0. If it is any positive number, then we have a contradiction.

If we ever come across a contradiction, then the log is necessarily inconsistent, so we can just output −1. Otherwise, the log must consist of several streaks 0,1,2,…,k of various lengths, with possibly some −1s between streaks - entries which we could not uniquely deduce. We know that the first streak starts on the first day.

Suppose there are s streaks and t entries that are still missing. Then to minimize the number of breakouts, each sequence of consecutive missing entries would be filled in so that it continues the streak preceding it (e.g. 0,1,2,3,−1,−1 would be filled in as 0,1,2,3,4,5). So the minimum number of breakouts is s.

To maximize the number of breakouts, the cows would have broken out on each of the t days for which the entry is missing (e.g. 0,1,2,3,−1,−1 would be filled in as 0,1,2,3,0,0). So the maximum number of breakouts is s+t.
    */

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    long long n;
    cin >> n;

    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    if (arr[0] > 0){
        cout << -1 << endl;
    }
    else{
        if (arr[0]==-1){
            arr[0] = 0;
        }
        long long maxi, mini;
        maxi = mini = 0;
        //*Stores what the next streak should be. 
        long long currStreak = -1;
        bool ok = true;
        for (long long i=n-1;i>=0;i--){
            if (arr[i]==-1){
                //*Meaning we are not in a middle of the streak: happens either at a start or after streak ended. 
                if (currStreak==-1){
                    //*Means we can make that a -1. 
                    //*Only add 1 to the maxi. 
                    maxi++;
                }
                else{
                    //*Keep decreasing the currStreak. 
                    currStreak--;
                }
            }
            //*Not negative 1 so it could be a new streak or an old streak. 
            else{
                if (currStreak==-1){
                    //*Can start a new streak. Start seriously counting from the next one. 
                    currStreak = arr[i]-1;

                    //!How am I gonna increment for maxi and mini at once. 
                    //*Once a streak is over, I should increment. 
                    //!Or increment whenever we start at streak. 
                    mini++;
                    maxi++;
                }
                else{
                    if (arr[i] != currStreak){
                        cout << -1 << endl;
                        ok = false;
                        break;
                    }
                    //*Otherwise on streak so just decrease streak count. 
                    else{
                        currStreak--;
                    }
                }
            }
        }

        if (ok){
            cout << mini << " " << maxi << endl;
        }
    }
}