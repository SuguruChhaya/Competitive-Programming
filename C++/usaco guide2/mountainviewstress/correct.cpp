#include <bits/stdc++.h>
using namespace std;
/*
bool compare(vector<long long> arr1, vector<long long>arr2){
    return arr1[1] > arr2[1];
}
*/
int main(){
    //freopen("mountains.in", "r", stdin);
    //freopen("mountains.out", "w", stdout);
    long long n;
    cin >> n;
    vector<vector<long long>> arr (n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    long long ans = 0;
    for (long long i=0;i<n;i++){
        bool ok = 1;
        for (long long j=0;j<n;j++){
            if (i!=j){
                //*Compare the 
                if (arr[i][0]<arr[j][0]){
                    if (!(arr[i][1]>arr[j][1]-(arr[j][0]-arr[i][0]))){
                        ok = 0;
                        break;
                    }
                }
                else{
                    if (!(arr[i][1]>arr[j][1]-(arr[i][0]-arr[j][0]))){
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok){
            ans++;
        }
    }
    cout << ans << endl;
}