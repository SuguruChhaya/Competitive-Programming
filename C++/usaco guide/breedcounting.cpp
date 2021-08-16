#include <bits/stdc++.h>

using namespace std;
int main(){

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    long long n, q;
    cin >> n >> q;
    //*Really just prefix sum but with 3 categories. 
    vector <vector <long long>> prefix_sum;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        vector <long long> next;
        if (i==0){
            next = {0, 0, 0};
            next[temp-1]++;
        }
        else{
            next = prefix_sum[prefix_sum.size()-1];
            next[temp-1]++;
        }
        prefix_sum.push_back(next);
    }

    for (long long i=0;i<q;i++){
        long long a, b;
        cin >> a >> b;
        vector <long long> result;
        result.push_back(prefix_sum[b-1][0]-prefix_sum[a-1][0]);
        result.push_back(prefix_sum[b-1][1]-prefix_sum[a-1][1]);
        result.push_back(prefix_sum[b-1][2]-prefix_sum[a-1][2]);
        result[arr[a-1]-1]++;
        cout << result[0] << " " << result[1] << " " << result[2] << endl;
    }
}