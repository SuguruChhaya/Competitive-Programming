#include <bits/stdc++.h>
using namespace std;




map <vector <long long>, long long> make(map <long long, vector <long long>> d){
    //!I have to adjust so that it is capitalized. 
    //long long zero = 0;
    map <vector <long long>, long long> t;
    for (long long i=((int) 'A');i<=((int)'A') + 26;i++){
        for (long long j=((int) 'A');j<=((int)'A') + 26;j++){
            t[{i, j}]=-1;
            deque <vector <long long>> q;
            q.push_back({j, 0});
            set <long long> visited;
            while (!q.empty()){
                auto curr = q[0];
                q.pop_front();
                if (curr[0]==i){
                    t[{i, j}] = curr[1];
                    break;
                }
                else if (visited.count(curr[0])==0 && d.count(curr[0])==1){
                    visited.insert(curr[0]);
                    for (auto e:d[curr[0]]){
                        q.push_back({e, curr[1]+1});
                    }
                }
            }
        }
    }
    return t;
}
int main(){
    long long te;
    cin >> te;
    //!Case 6 is failing. 
    for (long long i=1;i<=te;i++){
        string s;
        long long n;
        cin >> s >> n;
        map <long long, vector <long long>> d;
        for (long long j=0;j<n;j++){
            string temp;
            cin >> temp;
            d[(int) temp[1]].push_back((int) temp[0]);
        }
        //!I see this dictionary is only specific to that specific test case. 

        auto t = make(d);
        /*
        cout << "d" << endl;
        for (auto p:d){
            cout << p.first << endl;
            for (auto e:p.second){
                cout << e << " " << endl;
            }
            cout << endl;
        }

        for (auto p:t){
            cout << p.first[0] << " " << p.first[1] << " " << p.second << endl;
        }
        */
        long long large = 999999999;
        long long result = large;
        //!Need to loop from 'A' equivalent. 
        for (long long a=(int) 'A'; a<=(int) 'A' + 26;a++){
            long long temp = 0;
            bool ok = true;
            for (auto b:s){
                //!This place is giving me  seg error. 
                if (t[{(int) b, a}]==-1){
                    ok = false;
                    break;
                }
                else{
                    //cout << (int) b << a << endl;
                    //cout << t[{(int) b, a}] << endl;
                    temp += t[{(int) b, a}];
                }
            }
            if (ok){
                /*
                if (temp==9){
                    cout << t[{(int) 'F', (int) 'W'}] << endl;
                    cout << t[{(int) 'O', (int) 'W'}] << endl;
                    cout << t[{(int) 'X', (int) 'W'}] << endl;
                    cout << t[{(int) 'E', (int) 'W'}] << endl;
                    cout << t[{(int) 'N', (int) 'W'}] << endl;
                    
                    cout <<"";
                }
                */
                //!Hopefully no more issues...
                result = min(result, temp);
            }
        }
        if (result==large){
            result = -1;
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}