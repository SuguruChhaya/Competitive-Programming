#include <bits/stdc++.h>
using namespace std;
long long zero = 0;
int main(){
    long long n, m;
    cin >> n >> m;
    vector <long long> a(n), b(m);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }
    for (long long i=0;i<m;i++){
        cin >> b[i];
    }  
    long long r=0, curr=0;
    for (auto e:a){
        long long temp =99999999999;
        while (curr < m && b[curr]<e){
            temp = min(temp, e-b[curr]);
            curr++;
        }
        if (curr<m){
            temp = min(temp, b[curr]-e);
        }
        //*if the first cell tower is larger than house, curr will become -1. 
        curr = max(zero, curr-1);
        r = max(r, temp);
    }
    cout << r << endl;
}