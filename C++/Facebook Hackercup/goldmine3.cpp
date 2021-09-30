#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("a.in", "r", stdin);
    freopen("a", "w", stdout);
    long long t;
    cin >> t;
    //!Very similar to previous question but I fear that my solution might not run within the 6 minutes provided because of the large k.
    //!n^k is the options I can just around and max case that could be 50^50. 
    //*First implement naive solution, run against validation, and see how slow. 
    //*Possible optimizations. 
    //*I can make new tunnels connecting new tunnels right?
    //*I think that it is only beneficial to build new tunnels if that new tunnel still has gold. Otherwise why go there?
    //*Calculate the max I can get. If we already reach max, no point trying all those combinations. 
    //*If k>=n, we can always visit all so the answer will be max. 

    for (long long i=1;i<=t;i++){
        long long n, k;
        cin >> n >> k;
        
        vector <long long> c (n+1);
        long long max_possible = 0;
        for (long long j=1;j<=n;j++){
            cin >> c[j];
            max_possible+=c[j];
        }
        //!The thing is that we have to keep reading the input. 

        map <long long, map<long long, bool>>d;
        for (long long j=0;j<n-1;j++){
            long long a, b;
            cin >> a >> b;
            d[a][b] = 0;
            d[b][a] = 0;
        }
        long long result;
        if (k>=n){
            result = max_possible;
        }
        /*
        for (auto p:d){
            cout << "#" << p.first << endl;
            for (auto e:p.second){
                cout << e.first << " " << e.second << endl;
            }
        }
        */
        else{
            result = c[1];
            //!The fourth argument is the number of digs I used. 
            //*As long as smaller than max, I can keep digging. 
            deque <tuple <long long, long long, map <long long, map<long long, bool>>, long long, vector <long long>>> q;
            q.push_back({0, 1, d, 0, c});
        
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
                    if (get <3> (curr)<k){
                        for (long long j=1;j<=n;j++){
                            if (get <4> (curr)[j]!=0){
                                auto new_c = get <4> (curr);
                                long long add = new_c[get <1> (curr)];
                                new_c[get <1> (curr)] = 0;
                                q.push_back({get <0> (curr) + add, j, get <2> (curr), get <3> (curr) + 1, new_c});
                            }
                        }
                    }
                }
            }
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}