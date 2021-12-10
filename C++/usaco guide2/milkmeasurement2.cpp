#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    long long n, g;
    cin >> n >> g;
    vector <long long> arr (n+1, g);
    vector <vector <long long>> measurements (n, vector<long long>(3));
    for (long long i=0;i<n;i++){
        cin >> measurements[i][0] >> measurements[i][1] >> measurements[i][2];
    }
    sort(measurements.begin(), measurements.end());
    long long ans = 0;
    set <long long> prev;
    long long currMax = g;
    for (auto e:measurements){
        arr[e[1]]+=e[2];
        if (prev.count(e[1])){
            //*Was included, remove. 
            //!Check whether it increased or decreased from total. 
            ans++;
            if (arr[e[1]]>currMax){
                currMax = arr[e[1]];
                prev = {e[1]};
            }
            else{
                prev.erase(e[1]);
            }
        }
        else if (arr[e[1]]==currMax){
            ans++;
            prev.insert(e[1]);
        }
        else if (arr[e[1]]>currMax){
            ans++;
            currMax = arr[e[1]];
            prev = {e[1]};
        }
        /*
        long long currMax = 0;
        vector <long long> maxIndex;
        for (long long i=0;i<n;i++){
            if (arr[i]>currMax){
                currMax = arr[i];
                maxIndex = {i};
            }
            else if (arr[i]==currMax){
                maxIndex.push_back(i);
            }
        }
        if (prev!=maxIndex){
            ans++;
        }
        prev = maxIndex;
        */
    }
    cout << ans << endl;
}