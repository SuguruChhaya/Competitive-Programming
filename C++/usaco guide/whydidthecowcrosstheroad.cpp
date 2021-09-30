#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);

    long long n;cin>>n;
    vector <long long> arr (n+1, -1);    
    //*Just create a vector of initial size. 
    long long result = 0;
    for (long long i=0;i<n;i++){
        long long a, b;cin >> a >> b;
        if (arr[a]==-1){
            arr[a] = b;
        }
        else if (arr[a]!=b){
            result++;
            arr[a] = b;
        }
    }
    cout << result << endl;
}