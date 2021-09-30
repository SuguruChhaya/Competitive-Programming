#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    //*I think I am supposed to use sorting don't know how to connect that to 2 pointer. 
    vector <long long> arr (n);
    map <long long, vector <long long>> d;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
        //*I cannot store the index value in the set. 
        //*However, I could map all the values to a vector of indices. 
        d[arr[i]].push_back(i);
    }
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            if (d.count(x-arr[i]-arr[j])){
                for (auto e:d[x-arr[i]-arr[j]]){
                    if (e!=i && e!=j){
                        cout << i+1 << " " << j+1 << " " << e+1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    //*Set method worked but little over O(n^2). 
    
    cout << "IMPOSSIBLE" << endl;
}