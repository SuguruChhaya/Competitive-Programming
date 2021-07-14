#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    long long n;
    cin >>n;
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        long long arrive, take;
        cin >> arrive >> take;
        arr.push_back({arrive, take});
    }

    sort(arr.begin(), arr.end());

    long long curr_time = 0;
    for (auto element:arr){
        curr_time = max(curr_time, element[0]);
        curr_time+=element[1];
    }

    cout << curr_time << endl;
}