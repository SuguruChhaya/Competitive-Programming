#include <bits/stdc++.h>

using namespace std;
int main(){
    long long n, q;
    cin >> n >> q;
    vector <long long> arr;
    vector <long long> prefix_sum;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        if (i==0){
            prefix_sum.push_back(temp);
        }
        else{
            prefix_sum.push_back(prefix_sum[prefix_sum.size()-1]+temp);
        }
    }
    for (long long i=0;i<q;i++){
        long long a, b;
        cin >> a >> b;
        cout << prefix_sum[b-1]-prefix_sum[a]+arr[a] << "\n";
    }
}

//!In a 2dimensional prefix-sum array, each entry assumes that that entry is the right-bottom/. 
//*A real rectangular way to look at things. 