#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }   
    sort(arr.begin(), arr.end());

    //*Check the special cases. 
    //!And even within special cases there are more special cases when you can just move to the 1 empty space. 
    long long mini = 999999999999999;
    if ((arr[n-2]-arr[0]==n-2 && arr[n-1]-arr[n-2]>2) || (arr[n-1]-arr[1]==n-2 && arr[1]-arr[0]>2)){
        mini = 2;
    }
    else{
        long long j = 0;
        for (long long i=0;i<n;i++){
            while (j<n && arr[j]<=arr[i]+n-1){
                j++;
            }
            j--;
            mini = min(mini, n-(j-i+1));
        }
    }
    long long maxi = max(arr[n-2]-arr[0], arr[n-1]-arr[1])-(n-2);
    cout << mini << endl << maxi << endl;
}