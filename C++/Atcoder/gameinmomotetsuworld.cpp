#include <bits/stdc++.h>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;
    //*Create a 1-indexed vector. 
    long long large = 999999999999999;
    long long small = large * -1;
    vector <vector <long long>> dp;
    for (long long i=0;i<=h;i++){
        vector <long long> temp;    
        for (long long j=0;j<=w;j++){
            temp.push_back(large);
        }
        dp.push_back(temp);
    }
    //!I think it is worth giving it the +1 and -1 score. 

    vector <vector <long long>> arr;
    for (long long i=0;i<h;i++){
        string s;
        cin >> s;
        vector <long long> temp;
        for (long long j=0;j<w;j++){
            if (s[j]=='+'){
                temp.push_back(1);
            }
            else{
                temp.push_back(-1);
            }
        }
        arr.push_back(temp);
    }

    //*A BFS using a queue I guess. 
    //!Since I don't want a recursive BFS, start with the last one. 
    deque <vector <long long>> q;
    //*Gonna store the i and j index. 
    q.push_back({h, w});
    //dp[h][w] = 0;
    while (!q.empty()){
        auto curr = q[0];
        q.pop_front();
        //*Check whether in range and whether it has not been checked before. 
        if (1<=curr[0] && curr[0] <= h && 1<=curr[1] && curr[1] <= w && dp[curr[0]][curr[1]]==large){
            long long choose;
            //*Check whether we are looking at takashi starting or aoki. 
            if ((curr[0]+curr[1]) % 2 == 0){
                //*Starting at takahashi.
                choose = small;
                //!dp is 1-indexed but array is 0-indexed so kinda confusing??

                if (curr[0]+1<=h){
                    choose = max(choose, dp[curr[0]+1][curr[1]] + arr[curr[0]][curr[1]-1]);
                }
                if (curr[1]+1<=w){
                    choose = max(choose, dp[curr[0]][curr[1]+1] + arr[curr[0]-1][curr[1]]);
                }
            }
            else{
                //*Starting at aoki. 
                choose = large;
                if (curr[0]+1<=h){
                    choose = min(choose, dp[curr[0]+1][curr[1]] - arr[curr[0]][curr[1]-1]);
                }
                if (curr[1]+1<=w){
                    choose = min(choose, dp[curr[0]][curr[1]+1] - arr[curr[0]-1][curr[1]]);
                }
            }
            //!Only correct if we are at h, j
            if (curr[0]==h && curr[1]==w){
                choose = 0;
            }
            //*Fill the spot with choose. 
            dp[curr[0]][curr[1]] = choose;
            //*Push back the 2 adjacent cells. 
            q.push_back({curr[0]-1, curr[1]});
            q.push_back({curr[0], curr[1]-1});
        }


    }
    /*
    //*Print out the DP array. 
    for (long long i=0;i<dp.size();i++){
        for (long long j=0;j<dp[i].size();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    if (dp[1][1]==0){
        cout << "Draw" << endl;
    }
    else if (dp[1][1]>0){
        cout << "Takahashi" << endl;
    }
    else{
        cout << "Aoki" << endl;
    }
}