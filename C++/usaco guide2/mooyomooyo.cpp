#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<string> arr;
bool check = 1;
vector<vector<char>> visited;
vector<vector<bool>>erase;
long long currSize = 0;
void dfs(long long i, long long j, char currRegion, char val){
    if (i>=0&&i<n&&j>=0&&j<10&&visited[i][j]=='.'&&arr[i][j]==val){
        visited[i][j] = currRegion;
        currSize++;
        dfs(i-1, j, currRegion, val);
        dfs(i+1, j, currRegion, val);
        dfs(i, j-1, currRegion, val);
        dfs(i, j+1, currRegion, val);
    }
}
void findMoves(){
    check = 0;
    visited.resize(n, vector<char>(10, '.'));
    erase.resize(n, vector<bool>(10, 0));
    long long currRegion = 0;
    
    for (long long i=0;i<n;i++){
        for (long long j=0;j<10;j++){
            if (visited[i][j]=='.'){
                currSize = 0;
                dfs(i, j, currRegion, arr[i][j]);
                if (currSize>=k){
                    check = 1;
                    for (long long row=0;row<n;row++){
                        for (long long col=0;col<10;col++){
                            if (visited[row][col]==currRegion){
                                erase[row][col] = 1;
                            }
                        }
                    }
                }
                currRegion++;
            }
        }
    }
}
int main(){
    //?Who said n by n. 
    cin >> n >> k;
    arr.resize(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    findMoves();
    auto nextArr = arr;
    while (check){
        for (long long i=0;i<n;i++){
            for (long long j=0;j<10;j++){
                cout << erase[i][j] << " ";
            }
            cout << endl;
        }
        for (long long col=0;col<10;col++){
            long long newRow = n-1;
            for (long long row = n-1;row>=0;row--){
                if (erase[row][col]){
                    nextArr[newRow][col] = arr[row][col];
                    newRow--;
                }
            }
            for (;newRow>=0;newRow--){
                nextArr[newRow][col]++;
            }
        }
        for (long long i=0;i<n;i++){
            for (long long j=0;j<10;j++){
                cout << nextArr[i][j] << " ";
            }
            cout << endl;
        }
        swap(arr, nextArr);
        findMoves();
    }
    for (long long i=0;i<n;i++){
        cout << arr[i] << endl;
    }

}