#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    map <long long, vector <vector <long long>>> d;
    for (long long i=1;i<=2*n;i++){
        long long temp;
        cin >> temp;
        d[temp].push_back({i, 0});
    }
    //*Create vector and sort based on frequency. 
    vector <vector <long long>> sorted;
    for (auto p:d){
        sorted.push_back({p.second.size(), p.first});
    }
    sort(sorted.begin(), sorted.end(), greater<>());

    vector <vector <long long>> result;
    long long num = 0;
    //Loop through all elements in sorted. Use the second element as key. 
    for (auto p1:sorted){
        for (long long i=0;i<d[p1[1]].size();i++){
            if (d[p1[1]][i][1]==0){
                bool different = false;
                for (auto p2:d){
                    for (long long j=0;j<p2.second.size();j++){
                        if (p1[1]!=p2.first && d[p2.first][j][1]==0){
                            result.push_back({d[p1[1]][i][0], d[p2.first][j][0]});
                            //*Here I need index to change. 
                            d[p1[1]][i][1] = 1;
                            d[p2.first][j][1] = 1;
                            different = true;
                            num++;
                            break;
                        }
                    }
                    if (different){
                        break;
                    }
                }
                if (different==false){
                    for (long long j=0;j<d[p1[1]].size();j++){
                        if (d[p1[1]][j][1] ==0 && d[p1[1]][i][0]!=d[p1[1]][j][0]){
                            result.push_back({d[p1[1]][i][0], d[p1[1]][j][0]});
                            d[p1[1]][i][1] = 1;
                            d[p1[1]][j][1] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    //!I need a system to prioratize elements with higher frequencies. 
    //*
    cout << num << endl;
    for (auto e:result){
        cout << e[0] << " " << e[1] << endl;
    }
}