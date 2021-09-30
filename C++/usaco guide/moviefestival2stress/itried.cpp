//*In order to check for correct, just run the WA test case on it. 
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector <vector <long long>> arr (n, vector <long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    vector <bool> watched (n, 0);
    deque <tuple <long long, long long, long long, long long, vector <bool>>> q;
    q.push_back({0, 0, 0, 0, watched});
    long long ans = 0;
    while (!q.empty()){
        auto curr = q[0];
        cout << get <0> (curr) << get <1> (curr) << get <2> (curr) << get <3> (curr) << endl;
        for (auto e:get <4> (curr)){
            cout << e << endl;
        }
        q.pop_front();
        if (get <1> (curr)==k){
            ans = max(get <3> (curr), ans);
        }
        else{
            long long currMovie = get <2> (curr);
            while (currMovie<n && ((get <4> (curr))[currMovie]==1 || get <0> (curr) > arr[currMovie][0])){
                currMovie++;
            }
            if (currMovie==n){
                auto next = curr;
                get <0> (next) = 0;
                get <1> (next) = get <1> (curr)+1;
                get <2> (next) = 0;
            }
            else{
                auto next1 = curr;
                get <0> (next1) = arr[currMovie][1];
                get <3> (next1) = get <3> (curr) + 1;
                (get <4>(next1))[currMovie] = 1;
                q.push_back(next1);
                
                auto next2 = curr;
                get <2> (next2) = get <2> (curr) +1;
                q.push_back(next2);
            }
        }
    }
    cout << ans << endl;

}