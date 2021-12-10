#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>>arr (2001, vector<bool>(2001));

void floodfill(long long i, long long j){
    if (i>=0 && i<2001 && j>=0 && j<2001 && !arr[i][j]){
        arr[i][j]=1;
        floodfill(i-1, j);
        floodfill(i+1, j);
        floodfill(i, j-1);
        floodfill(i, j+1);
    }
}

int main(){
    long long n;
    cin >> n;
    long long row = 1000, col=1000;
    map <char, vector <long long>> d = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'W', {0, -1}},
        {'E', {0, 1}}
    };
    for (long long i=0;i<n;i++){
        char c;
        cin >> c;
        arr[row][col] = 1;
        row+=d[c][0], col+=d[c][1];
    }
    long long ans = -1;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (!arr[i][j]){
                ans++;
                floodfill(i, j);
            }
        }
    }
    cout << ans << endl;
}