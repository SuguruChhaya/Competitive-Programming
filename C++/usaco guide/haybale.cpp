#include <bits/stdc++.h>

using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    vector <long long> arr;
    for (long long i=0;i<=n;i++){
        arr.push_back(0);
    }

    for (long long i=0;i<k;i++){
        long long a, b;
        cin >> a >> b;
        for (long long j=a;j<=b;j++){
            arr[j]++;
        }
    }
    sort(arr.begin(), arr.end());

    cout << arr[(n+1) / 2] << endl;
}