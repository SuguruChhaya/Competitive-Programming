#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        long long a, b;
        cin >> a >> b;
        arr.push_back({a, i});
        arr.push_back({b, i});
    }
    sort(arr.begin(), arr.end());
    //!First thing I suspect is whether this is sorted properly.

    long long ans = 0;
    set <long long> s;
    vector <long long> aloneTime (n, 0);
    long long last = 0, covered = 0;
    for (auto e:arr){
        if (s.size()==1){
            //cout << *s.begin() << endl;
            aloneTime[(*s.begin())] += e[0]-last;
        }
        if (!s.empty()){
            covered += e[0]-last;
        }
        if (s.count(e[1])){
            s.erase(e[1]);
        }
        else{
            s.insert(e[1]);
        }
        last = e[0];
    }
    //long long ans = 0;
    for (auto e:aloneTime){
        ans = max(ans, covered-e);
    }
    cout << ans << endl;
}