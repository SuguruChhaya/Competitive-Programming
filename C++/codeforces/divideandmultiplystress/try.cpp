#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    /*
    long long r = -1;
    for (long long i=0;i<n;i++){
        //!Obviously increasing 1 isn't a good idea. 
        if (arr[i]%2==1){
            r=i;
        }
    }
    if (r==-1){
        r = n-1;
    }
    */
    for (auto e:arr){
        cout << e << " ";
    }
    cout << endl;
    for (long long i=0;i<n;i++){
        if (i!=n-1){
            while (arr[i]%2==0){
                arr[i]/=2;
                arr[n-1]*=2;
            }
        }
    }
    long long ans = 0;
    for (auto e:arr){
        ans+=e;
    }
    sort(arr.begin(), arr.end());
    for (auto e:arr){
        cout << e << " ";
    }
    cout << endl;
    long long oddIndex = -1;
    for (long long i=n-1;i>=0;i--){
        if (arr[i]%2==1){
            oddIndex = i;
            break;
        }
    }
    for (auto e:arr){
        cout << e << " ";
    }
    cout << endl;
    if (oddIndex!=-1){
        while (arr[n-1]%2==0){
            arr[oddIndex] *=2;
            arr[n-1] /= 2;
        }
        long long increaseOdd = 0;
        for (auto e:arr){
            increaseOdd+=e;
        }
        ans = max(ans, increaseOdd);
    }

    cout << ans << endl;
}

int main(){
    /*
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
    */
    solve();
}