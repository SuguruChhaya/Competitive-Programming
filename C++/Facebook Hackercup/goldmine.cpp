#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    //!Very similar to previous question but I fear that my solution might not run within the 6 minutes provided because of the large k.
    for (long long i=1;i<=t;i++){
        long long n;
        cin >> n;
        vector <long long> c (n+1);
        for (long long j=1;j<=n;j++){
            cin >> c[j];
        }
        map <long long, map<long long, bool>>d;
        for (long long j=0;j<n-1;j++){
            long long a, b;
            cin >> a >> b;
            d[a][b] = 0;
            d[b][a] = 0;
        }
        /*
        for (auto p:d){
            cout << "#" << p.first << endl;
            for (auto e:p.second){
                cout << e.first << " " << e.second << endl;
            }
        }
        */
        long long result = c[1];
        deque <tuple <long long, long long, map <long long, map<long long, bool>>, bool, vector <long long>>> q;
        q.push_back({0, 1, d, 1, c});
    
        while (!q.empty()){
            auto curr = q[0];
            //*If stuck, I could print all the values. 
            /*
            cout << get <0> (curr) << " " << get <1> (curr) << endl;
            if (get <0> (curr)==2 && get <1> (curr)==1){
                cout << get <2> (curr)[2][1] << endl;
            }
            */
            q.pop_front();
            if (get <1> (curr)==1 && (get <4>(curr))[1]==0){
                result = max(result, get <0> (curr));
            }
            else{
                //!Cannot iterate over d
                for (auto p:(get <2> (curr))[get <1> (curr)]){
                    if (p.second==0){
                        auto new_d = get <2> (curr);
                        new_d[get<1> (curr)][p.first] = 1;
                        new_d[p.first][get <1> (curr)] = 1;
                        auto new_c = get <4> (curr);
                        long long add = new_c[get <1> (curr)];
                        new_c[get <1> (curr)] = 0;
                        q.push_back({get <0> (curr)+add, p.first, new_d, get <3> (curr), new_c});
                    }
                }
                if (get <3> (curr)==1){
                    for (long long j=1;j<=n;j++){
                        auto new_c = get <4> (curr);
                        long long add = new_c[get <1> (curr)];
                        new_c[get <1> (curr)] = 0;
                        q.push_back({get <0> (curr) + add, j, get <2> (curr), 0, new_c});
                    }
                }
            }
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}