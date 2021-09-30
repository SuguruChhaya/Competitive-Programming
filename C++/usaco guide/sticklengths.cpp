#include <bits/stdc++.h>
using namespace std;

int main(){
    //?How is this a greedy? It isn't as if I need to adjust to an existing value too...
    //Using median
    long long n;
    cin >> n;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long median;
    if (n%2==0){
        median = (arr[n/2] + arr[n/2-1])/2;
        //*Even if not completely divisible, I think I can round off. 
    }
    else{
        median = (arr[n/2]);
    }
    long long ans = 0;
    for (auto e:arr){
        ans += abs(e-median);
    }
    cout << ans << endl;
}