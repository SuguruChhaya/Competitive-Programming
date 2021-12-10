#include <bits/stdc++.h>
using namespace std;

long long firstZero(vector<vector<long long>> arr){
    for (long long i=0;i<arr.size();i++){
        if (arr[i].size()==0){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> arr(n);
    vector <long long> dist (n, 0);
    long long currCow = 0;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        for (long long j=0;j<temp;j++){
            arr[i].push_back(currCow);
            currCow++;
        }
    }
    /*
    for (long long i=0;i<n;i++){
        for (long long j=0;j<arr[i].size();j++){
            cout << arr[i][j]<< endl;
        }
        cout << endl;
    }
    */
    long long i=firstZero(arr);
    while (i!=-1){
        //cout << i << endl;
        long long j=i;
        long long d = 0;
        while (arr[j].size()==0){
            j--;
            d++;
            if (j==-1){
                j = n-1;
            }
        }

        dist[arr[j][arr[j].size()-1]]+=d;
        //cout << dist.size() << endl;
        arr[i].push_back(arr[j][arr[j].size()-1]);
        arr[j].pop_back();
        i = firstZero(arr);
    }
    long long ans = 0;
    for (auto e:dist){
        //cout << e << endl;
        ans+=pow(e, 2);
    }
    //cout << endl;
    cout << ans << endl;
}