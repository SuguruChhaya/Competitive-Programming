#include <bits/stdc++.h>
using namespace std;

bool compare(vector<long long> arr1, vector<long long>arr2){
    return arr1[1] > arr2[1];
}

int main(){
    //freopen("mountains.in", "r", stdin);
    //freopen("mountains.out", "w", stdout);
    long long n;
    cin >> n;
    vector<vector<long long>> arr (n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end(), compare);
    
    for (long long i=0;i<n;i++){
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
    //!Don't have to look at all. 
    long long l=0, r=0, ans=1;
    for (long long i=1;i<n;i++){
        if (arr[i][0]<=arr[l][0]){
            if (arr[i][1]>arr[l][1]-(arr[l][0]-arr[i][0])){
                ans++;
                l=i;
            }
        }
        else{
            if (arr[i][1]>arr[r][1]-(arr[i][0]-arr[r][0])){
                ans++;
                r = i;
            }
        }
    }
    cout << ans << endl;
}