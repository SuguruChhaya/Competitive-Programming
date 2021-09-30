#include <bits/stdc++.h>
using namespace std;


int main(){
    //*Really famous question but forgot how to do this one. 
    long long n;cin >> n;

    vector <long long> prefix (n,0);
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        if (i==0){
            prefix[i] = temp;
        }
        else{
            prefix[i] = prefix[i-1]+temp;
        }
    }
    long long result =-999999999999;
    long long currMin = 0;
    for (long long i=0;i<n;i++){
        
        result = max(result, prefix[i]-currMin);
        currMin = min(currMin, prefix[i]);
    }
    cout << result << endl;
}