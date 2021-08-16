#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    long long n;
    cin >> n;
    vector <long long> prefix, arr;
    //!I think a quadratic solution will work. 
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        if (i==0){
            prefix.push_back(temp);
        }
        else{
            prefix.push_back(prefix[i-1]+temp);
        }
        arr.push_back(temp);
    }
    //*Pick 2 indices.
    long long result =0; 
    for (long long i=0;i<n;i++){
        for (long long j=i;j<n;j++){
            if ((prefix[j]-prefix[i]+arr[i]) % 7==0){
                result = max(j-i+1, result);
            }
        }
    }
    cout << result << endl;
}