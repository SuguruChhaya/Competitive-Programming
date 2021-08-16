#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector <long long> a, b;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (long long i=0;i<m;i++){
        long long temp;
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long min_difference = 999999999999999;
    long long i=0, j=0;
    while (i < n && j <m){
        min_difference = min(abs(a[i]-b[j]), min_difference);
        if (a[i] > b[j]){
            j++;
        }
        else if (a[i]<=b[j]){
            i++;
        }
    }

    cout << min_difference << "\n";
}