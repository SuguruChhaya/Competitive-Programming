#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, k;
        cin >> n >> k;
        vector <long long> arr;
        vector <long long> result;

        //*Map seems good but might TLE...
        //*Stores the indexes of where the element appears. 
        map <long long, vector <long long>> d;
        for (long long i=0;i<n;i++){
            long long temp;
            cin >> temp;
            arr.push_back(temp);
            result.push_back(0);
            //*Because the default is not colored. 
            if (d.count(temp)==1){
                d[temp].push_back(i);
            }
            else{
                d.insert({temp, {i}});
            }
        }

        long long currColor = 1;
        for (auto p:d){
            //*Loop through all the indexes. 
            bool add = true;
            long long started_at = currColor;
            for (auto index:p.second){
                //*I could do the increase check at the end. 
                //*Need a bool value to check whether we are even gonna color this thing. 
                //!Every time we switch to a new pair, we have to set the bool value to true. 
                //!Not necessarily true that we will end at the kth element since continuously assigning. Need to keep track how many I have assigned. 

                if (add){
                    result[index] = currColor;
                    currColor++;
                    if (currColor > k){
                        currColor=1;
                    }
                    if (currColor==started_at){
                        add = false;
                    }
                }
            }
        }

        for (auto e: result){
            cout << e << " ";
        }
        cout << endl;



    }
}