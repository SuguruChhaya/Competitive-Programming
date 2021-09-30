#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pairup.in", "r", stdin);
    //freopen("pairup.out", "w", stdout);
    //*Reserving so much space for vector->MLE. 
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        for (long long j=0;j<x;j++){
            arr.push_back(y);
        }
    }
    sort(arr.begin(), arr.end());

    long long left = 0, right = arr.size()-1, result = -1;
    while (left<=right){
        result=max(result, arr[left]+arr[right]);
        left++;
        right--;
    }
    cout << result << endl;
}