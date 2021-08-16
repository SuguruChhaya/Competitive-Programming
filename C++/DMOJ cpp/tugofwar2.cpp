#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector <long long> arr, prefix_sum;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        if (i==0){
            prefix_sum.push_back(temp);
        }
        else{
            prefix_sum.push_back(temp+prefix_sum[i-1]);
        }
    }
    vector <long long> result_arr;

    //*The splitting part probably has to be done manually through loop. 
    for (long long l=0;l<n;l++){
        //*Make it a double?
        arr.push_back(arr[l]);
        //*Keep adding it on the prefix sum. 
        prefix_sum.push_back(arr[arr.size()-1]+prefix_sum[prefix_sum.size()-1]);

    }
    for (long long l=0;l<n;l++){
        long long curr_min = 99999999999999999;
        long long curr_split = l;
        for (long long j=0;j<n;j++){
            long long team_a = prefix_sum[curr_split+j] - prefix_sum[l] + arr[l];
            curr_min = min(curr_min, abs(team_a-prefix_sum[n-1]+team_a));

        }
        result_arr.push_back(curr_min);
    }
    for (long long i=0;i<n;i++){
        if (i==0){
            cout << result_arr[i];
        }
        else{
            cout << " " << result_arr[i];
        }
    }
    cout << endl;

}