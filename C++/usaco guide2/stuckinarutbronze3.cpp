#include <bits/stdc++.h>
using namespace std;

bool compareNorth(vector<long long>arr1, vector<long long>arr2){
    return arr1[0] < arr2[0];
}
bool compareEast(vector<long long>arr1, vector<long long>arr2){
    return arr1[1] < arr2[1];
}
int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> north, east;
    for (long long i=0;i<n;i++){
        char c;
        long long x, y;
        cin >> c >> x >> y;
        if (c=='N'){
            north.push_back({x, y, i});
        }
        else{
            east.push_back({x, y, i});
        }
    }
    sort(north.begin(), north.end(), compareNorth);
    sort(east.begin(), east.end(), compareEast);
    vector<long long> amount(n, -1);
    vector<bool> isStopped(n,0);
    for (auto i:north){
        for (auto j:east){
            if (!isStopped[i[2]] && !isStopped[j[2]] && i[0]>j[0] && j[1]>i[1]){
                //*Case for the one going north to stop. 
                long long x = i[0], y = j[1];
                if (x-j[0]<y-i[1]){
                    isStopped[i[2]] = 1;
                    amount[i[2]] = y-i[1];
                }
                else if (x-j[0]>y-i[1]){
                    isStopped[j[2]] = 1;
                    amount[j[2]] = x-j[0];
                }
            }
        }
    }
    for (auto e:amount){
        if (e==-1){
            cout << "Infinity" << endl;
        }
        else{
            cout << e << endl;
        }
    }
}