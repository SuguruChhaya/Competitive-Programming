#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    cin >> n >> q;
    vector <long long> arr(n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
    }
    for (long long i=0;i<q;i++){
        long long l, r;
        cin >> l >> r;
        map <long long, long long> d;
        for (long long j=l;j<=r;j++){
            d[arr[j]]++;
        }
        long long maxi = 0;
        vector <long long> scores;
        for (auto e:d){
            if (e.second>maxi){
                maxi = e.second;
                scores = {e.first};
            }
            else if (e.second==maxi){
                scores.push_back(e.first);
            }
        }
        sort(scores.begin(), scores.end(), greater<long long>());
        cout << scores[0] << endl;
    }
}