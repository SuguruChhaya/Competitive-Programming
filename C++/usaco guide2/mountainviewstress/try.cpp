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
    

}