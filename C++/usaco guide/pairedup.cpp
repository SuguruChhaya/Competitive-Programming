//*Don't wanna create a vector since could cost upto 10^9. Use math. 
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pairup.in", "r", stdin);
    //freopen("pairup.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][1] >> arr[i][0];
    }
    sort(arr.begin(), arr.end());
    long long left = 0, right = n-1, ans=9999999999999;
    while (left<=right){
        //cout << left << " " << right << endl;
        long long remove = min(arr[left][1], arr[right][1]);
        ans = min(ans, arr[left][0]+arr[right][0]);
        if (left==right){
            arr[left][1]-=remove;
        }
        else{
            arr[left][1]-=remove;
            arr[right][1]-=remove;
        }
        //!Need special treatment if we are at the same index. 
        if (arr[left][1]==0){
            left++;
        }
        if (arr[right][1]==0){
            right--;
        }
    }
    cout << ans << endl;
}