#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("leftout.in", "r", stdin);
    //freopen("leftout.out", "w", stdout);
    long long n;
    cin >> n;
    vector<vector<bool>> arr (n, vector<bool>(n, 0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            char c;
            cin >> c;
            if (c=='L'){
                arr[i][j] = 0; 
            }
            else{
                arr[i][j] = 1;
            }
        }
    }

    for (long long col = 0;col<n;col++){
        if (arr[0][col]==1){
            for (long long row=0;row<n;row++){
                arr[row][col] = !arr[row][col];
            }
        }
    }
    for (long long row=0;row<n;row++){
        if (arr[row][0]==1){
            for (long long col=0;col<n;col++){
                arr[row][col] = !arr[row][col];
            }
        }
    }

    vector<vector<long long>> ones;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (arr[i][j]){
                ones.push_back({i, j});
            }
        }
    }
    if (ones.size()==1){
        cout << ones[0][0]+1 << " " << ones[0][1]+1 << endl;
    }
    else if (ones.size()==0){
        cout << -1 << endl;
    }
    else{
        //*Check whether they are all in the same row or column. 
        bool sameRow = true, sameCol = true;
        long long firstRow=ones[0][0], firstCol = ones[0][1];
        for (auto e:ones){
            if (e[0]!=firstRow){
                sameRow = 0;
            }
            if (e[1]!=firstCol){
                sameCol = 0;
            }
        }
        if (sameRow && ones.size()==n-1){
            cout << firstRow+1 << " " << 1 << endl; 
        }
        else if (sameCol && ones.size()==n-1){
            cout << 1 << " " << firstCol+1 << endl;
        }
        else if (ones.size()==(n-1)*(n-1)){
            //*Square exists. 
            cout << 1 << " " << 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}