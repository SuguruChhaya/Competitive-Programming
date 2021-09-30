#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <long long> arr (n+1), result(n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
    }
    for (long long i=1;i<=n;i++){
        result[arr[i]] = i;
    }
    for (long long i=1;i<=n;i++){
        cout << result[i] << " ";
    }
    cout << endl;
}