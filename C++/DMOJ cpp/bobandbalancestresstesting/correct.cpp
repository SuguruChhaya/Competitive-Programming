#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <vector <long long>> w (2*n, vector <long long> (2));
    for (long long i=0;i<2*n;i++){
        cin >> w[i][0];
        w[i][1] = i+1;
    }
    deque <pair <vector <vector <vector <long long>>>, vector <vector <long long>>>> q;
    q.push_back({{}, w});
    vector <vector <vector <long long>>> result;
    long long tipping = 0;
    while (!q.empty()){

        auto curr = q[0];
        q.pop_front();
        /*
        cout << "first" << endl;
        for (auto a:curr.first){
            for (auto b:a){
                cout << b[0] << " " << b[1] << endl;
            }
        }
        cout << "second" << endl;
        for (auto a:curr.second){
            cout << a[0] << " " << a[1] << endl;
        }
        //*Need to carefully observe. 
        */
        if (curr.first.size()==n){
            long long temp = 0;
            for (auto p:curr.first){
                if (p[0][0]!=p[1][0]){
                    temp++;
                }
            }
            if (temp>tipping){
                result = curr.first;
                tipping= temp;
            }
        }
        else{
            for (long long i=1;i<curr.second.size();i++){
                pair <vector <vector <vector <long long>>>, vector <vector <long long>>> temp;
                temp.first = curr.first;
                temp.first.push_back({curr.second[0], curr.second[i]});
                for (long long j=1;j<curr.second.size();j++){
                    if (j!=i){
                        //!Not enough information. 
                        //!Actually, there is enough info. 
                        temp.second.push_back(curr.second[j]);
                    }
                }
                q.push_back(temp);
            }
        }
    }
    cout << tipping << endl;
    for (auto e:result){
        cout << e[0][1] << " " << e[1][1] << endl;
    }

}