#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> a, b;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            b.push_back(temp);
        }

        //*Too much to generate all of them. 
        //!I picture a BFS-ish comparison where the smallest for that round remains and gets compared with those that survived the round. 

        deque <pair <vector <long long>, long long>> q;
        //*Initially add all of them into the queue, 
        for (long long j=0;j<n;j++){
            pair <vector <long long>, long long> add;
            add.first = {};
            add.second = j;
            q.push_back(add);
        }
        long long counter = 0;
        while (q.size() != 1 && counter <n){
            long long min_mod = 99999999999999;
            for (auto p:q){
                min_mod = min(min_mod, (a[p.second]+b[p.second]) % n);
            }
            deque <pair <vector <long long>, long long>> next;
            for (auto p:q){
                if (p.second==min_mod){
                    auto add = p;
                    add.first.push_back(min_mod);
                    add.second = (add.second+1) % n;
                    next.push_back(add);
                }
            }
            counter++;
            q = next;
        }

        for (long long j=0;j<n;j++){
            cout << q[0].first[j] << " ";
        }
        cout << "\n";
    } 
}