#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Shouldn't I try to switch every time?
    //*Have array of the number of times I can win with rock, scissors and paper. 
    
    //!Might be easier if I make it a 2D vector so I can prevent so many if statements. 

    long long n;
    cin >> n;

    vector <vector <long long>> arr;
    for (long long i=0;i<3;i++){
        vector <long long> temp;
        for (long long j=0;j<n;j++){
            temp.push_back(0);
        }
        arr.push_back(temp);
    }//!Correct order is H, P, S
    for (long long i=0;i<n;i++){
        char temp;
        cin >> temp;
        if (temp=='H'){
            arr[1][i]++;
        }
        else if (temp=='P'){
            arr[2][i]++;
        }
        else if (temp=='S'){
            arr[0][i]++;
        }
        //*Carry over. 
        if (i>0){
            arr[0][i] += arr[0][i-1];
            arr[1][i] += arr[1][i-1];
            arr[2][i] += arr[2][i-1];
            
        }
    }

    for (long long i=0;i<arr.size();i++){
        for (long long j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    long long result = 0;
    //*Just pick the values to switch into and then run a linear loop. 
    for (long long i=0;i<3;i++){
        for (long long j=0;j<3;j++){
            long long num_wins = 0;
            //*We could possibly do all of them so n+1
            for (long long k=0;k<=n;k++){
                if (k>0){
                    //*Stuff on the left side. 
                    num_wins+=arr[i][k-1];
                }
                if (k<n){
                    //*Stuff on the right side. 
                    //!Right side is computed a little differently?
                    num_wins+=arr[j][n-1]-arr[j][k-1];
                }
                result = max(result, num_wins);
            }
        }
    }

    cout << result << endl;
}