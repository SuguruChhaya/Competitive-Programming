#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    long long n, g;
    cin >> n >> g;
    vector <vector <long long>> measurements (n, vector<long long>(3));
    for (long long i=0;i<n;i++){
        cin >> measurements[i][0] >> measurements[i][1] >> measurements[i][2];
    }
    sort(measurements.begin(), measurements.end());

    //*Use map to store important value. 
    map <long long, long long> d;
    long long ans = 0;
    set <long long> prev;
    long long currMax = g;
    for (auto e:measurements){
        //*Start of with g.
        if (!d.count(e[1])){
            d[e[1]] = g;
        }
        /*
        if (e[1]==5 && e[2]==3){
            cout << "";
        } //?Didn't it just ignore 6 5?
        */
        //?But what if all of them are at g and one goes down? 
        d[e[1]] += e[2];
        //cout << d[e[1]] << endl;
        if (prev.count(e[1])){
            if (prev.size()==1){
                //!If it is still on top, nothing changes. 
                //!Regardless of whether it is larger or smaller, recalculate it. 
                currMax = 0;
                set <long long> newPrev = {};
                for (auto p:d){
                    if (p.second>currMax){
                        if (p.second>currMax){
                            currMax = p.second;
                            newPrev = {p.first};
                        }
                        else if (p.second==currMax){
                            newPrev.insert(p.first);
                        }
                    }
                }
                if (g>currMax){
                    currMax = g;
                    newPrev = {};
                }
                if (prev!=newPrev){
                    ans++;
                    prev = newPrev;
                }
                /*
                if (d[e[1]]>currMax){
                    currMax = d[e[1]];
                }
                else{
                    ans++;
                    //*Find the second largest
                    currMax =0;
                    prev={};
                    for (auto p:d){
                        if (p.second>currMax){
                            currMax = p.second;
                            prev = {p.first};
                        }
                        else if (p.second==currMax){
                            prev.insert(p.first);
                        }
                    }
                    if (g>currMax){
                        currMax = g;
                        //?Don't really know what I can do for the vector...
                        prev = {};
                    }
                }
                */
            }
            else{
                if (d[e[1]]>currMax){
                    currMax = d[e[1]];
                }
                else{
                    //*There are others that still tied. 
                    prev.erase(e[1]);
                }
            }
        }
        else if (d[e[1]]==currMax){
            ans++;
            prev.insert(e[1]);
        }
        else if (d[e[1]]>currMax){
            ans++;
            currMax = d[e[1]];
            prev = {e[1]};
        }
    }
    cout << ans << endl;
}