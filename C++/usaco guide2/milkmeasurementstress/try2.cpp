#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
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

        //!Whether the set becomes an include or exclude depends on the maximum. 

        if (currMax==g){
            //*What is there is an exclude. 
            if (prev.count(e[1])){
                //!Does it matter if the size is 1 or no?
                //*Only case it may matter is if erased. 
                //*currMax stays at g and prev is empty. 
                if (d[e[1]]>g){
                    ans++;
                    currMax = d[e[1]];
                    prev = {e[1]};
                }
                    
                else if (d[e[1]]==g){
                    ans++;
                    prev.erase(e[1]);
                }
            }
            else{
                //*Doesn't exist in prev. 
                if (d[e[1]]>g){
                    ans++;
                    currMax = d[e[1]];
                    prev = {e[1]};
                }
                else if (d[e[1]]<g){
                    ans++;
                    prev.insert(e[1]);
                }
        
            }

        }
        else{
            //*currMax > g
            //*includes 
            //!Forgot to check whether it includes or not. 
            if (prev.count(e[1])){
                if (prev.size()==1){
                    if (d[e[1]]>currMax){
                        currMax = d[e[1]];
                    }
                    else{
                        long long newMax = g;
                        set <long long> newPrev = {};
                        for (auto p:d){
                            if (p.second>newMax){
                                newMax = p.second;
                                newPrev = {p.first};
                            }
                            else if (p.second==newMax){
                                newPrev.insert(p.first);
                            }
                        }
                        if (newMax==g){
                            newPrev = {};
                            //*Change it to an excludes set. 
                            ans++;
                            for (auto p:d){
                                if (p.second<g){
                                    newPrev.insert({p.first});
                                }
                            }
                        }
                        else{
                            if (newPrev==prev){
                                //*If decreased but the single one is still on top.
                                
                            }
                            else{
                                ans++;
                            }
                        }
                        currMax = newMax;
                        prev = newPrev;
                    }
                }
                else{
                    if (d[e[1]]>currMax){
                        ans++;
                        currMax=d[e[1]];
                        prev = {e[1]};
                    }
                    else{
                        ans++;
                        prev.erase(e[1]);
                    }
                }
            }
            else{
                if (d[e[1]]>currMax){
                    ans++;
                    currMax = d[e[1]];
                    prev = {e[1]};
                }
                else if (d[e[1]]==currMax){
                    ans++;
                    prev.insert(e[1]);
                }
            }
        }
        
    }
    cout << ans << endl;
}