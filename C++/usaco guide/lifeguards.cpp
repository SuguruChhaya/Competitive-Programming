#include <bits/stdc++.h>

using namespace std;

int main(){
    //*I could just try removing every single lifeguard and calculate. 
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    long long n;
    cin >> n;
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        long long a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    //*Create the template vector. 
    vector <bool> original;
    for (long long i=0;i<1000;i++){
        original.push_back(0);
    }

    long long result = 0;
    //*Now remove every single one. 
    for (long long i=0;i<n;i++){
        auto curr = original;
        for (long long j=0;j<n;j++){
            //!Need to be careful with the points. 
            if (j==i){

            }
            else{
                for (long long k=arr[j][0]; k<arr[j][1]; k++){
                    curr[k] = 1;
                }
            }
        }

        //*After fill tally up and compare with result. 
        long long curr_result = 0;
        for (long long j=0;j<1000;j++){
            if (curr[j]==true){
                curr_result++;
            }
        }
        result = max(result, curr_result);
    }

    cout << result << endl;
}