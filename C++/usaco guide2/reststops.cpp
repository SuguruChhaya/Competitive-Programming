#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    long long l, n, f, b;
    cin >> l >> n >> f >> b;
    vector <vector<long long>> arr(n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    long long left = 0;
    vector<long long>indices;

    while (left<n){
        long long maxVal = 0, maxIndex;
        for (long long i=left;i<n;i++){
            if (arr[i][1]>maxVal){
                maxIndex = i;
                maxVal = arr[i][1];
            }
        }
        indices.push_back(maxIndex);
        left = maxIndex + 1;
    }
    long long curr = 0, ans = 0;
    /*
    for (auto e:indices){
        cout << e << endl;
    }
    */
    for (auto e:indices){
        ans += arr[e][1] * ((arr[e][0]-curr) * (f-b));
        curr = arr[e][0];
    }
    cout << ans << endl;
}   