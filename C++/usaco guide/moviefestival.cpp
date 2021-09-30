#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][1] >> arr[i][0];
    }
    sort(arr.begin(), arr.end());
    long long currTime = 0, ans=0;
    for (auto e:arr){
        if (e[1]>=currTime){
            currTime=e[0];
            ans++;
        }
    }
    cout << ans << endl;
}