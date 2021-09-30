#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector <long long> line;
    for (long long i=n-1;i>=0;i--){
        if (line.size()<=arr[i]){
            line.push_back(arr[i]);
        }
    }
    cout << line.size() << endl;
}