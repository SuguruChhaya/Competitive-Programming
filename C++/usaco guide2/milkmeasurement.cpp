#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    long long n, g;
    cin >> n >> g;
    vector <long long> arr (n+1, g);
    vector <vector <long long>> measurements (n, vector<long long>(3));
    for (long long i=0;i<n;i++){
        cin >> measurements[i][0] >> measurements[i][1] >> measurements[i][2];
    }
    sort(measurements.begin(), measurements.end());
    long long ans = 0;
    vector <long long> prev;
    for (auto e:measurements){
        arr[e[1]]+=e[2];
        long long currMax = 0;
        vector <long long> maxIndex;
        for (long long i=0;i<n;i++){
            if (arr[i]>currMax){
                currMax = arr[i];
                maxIndex = {i};
            }
            else if (arr[i]==currMax){
                maxIndex.push_back(i);
            }
        }
        if (prev!=maxIndex){
            ans++;
        }
        prev = maxIndex;
    }
    cout << ans << endl;
}