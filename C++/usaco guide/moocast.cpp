#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <long long>> arr;
vector <bool> used;
long long temp;
long long result = 0;

void dfs(long long index){
    used[index]=1;
    temp++;
    for (long long i=0;i<n;i++){
        if (used[i]==0&&sqrt(pow(arr[i][0]-arr[index][0], 2)+pow(arr[i][1]-arr[index][1], 2))<=arr[index][2]){
            dfs(i);
        }
    }
}
int main(){
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    cin >> n;
    arr.resize(n, vector <long long>(3));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    //used.resize(n, 0);
    for (long long i=0;i<n;i++){
        temp=0;
        used.resize(n, 0);
        dfs(i);
        result = max(result, temp);
    }
    cout << result << endl;
}