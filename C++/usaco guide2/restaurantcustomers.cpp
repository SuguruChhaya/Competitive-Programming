#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Cast and create every single permutation. 
    long long n;
    cin >> n;
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        long long a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    long long ans = 0, curr = 0;
    for (auto e:arr){
        curr += e[1];
        ans = max(ans, curr);
    }
    cout << ans << endl;
}