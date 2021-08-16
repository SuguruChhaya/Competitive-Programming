#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Cannot do n^2. 
    //*Including the maximum is easy 
    //*Always optimal is 2 pairing. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> arr;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            arr.push_back(temp);
        }
        long long result = 0;
        for (long long j=0;j<n-1;j++){
            //*Group up with next index. 
            result = max(result, arr[j]*arr[j+1]);
        }
        cout << result << "\n";
    }
}