#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector <long long> a(n), b(n);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }
    for (long long i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long mini = 1, maxi = 1;
    long long i=0, j=0;
    while (i<a.size()&&j<b.size()){
        mini*=(1+a[i]+b[i]);
        i++, j++;
    }
    while (i<a.size()){
        mini*=(1+a[i]);
        i++;
    }
    while (j<b.size()){
        mini*=(1+b[i]);
        j++;
    }
    i = 0, j=0;
    while (i<a.size()){
        maxi*=(1+a[i]);
        i++;
    }
    while (j<b.size()){
        maxi *= (1+b[j]);
        j++;
    }
    cout << mini%1000000007 <<" " << maxi%1000000007 << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}