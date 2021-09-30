#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    long long result =0;
    long long ans = 0;
    while (arr!=sorted){
        result++;
        if (result % 2==1){
            for (long long i=0;i<n-1;i+=2){
                if (arr[i]>arr[i+1]){
                    long long temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
        else{
            for (long long i=1;i<n-1;i+=2){
                if (arr[i]>arr[i+1]){
                    long long temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
        /*
        for (auto e:arr){
            cout << e << endl;
        }
        */
    }
    cout << result << endl;
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}