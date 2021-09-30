#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    //*Never thought of using binary search to find the ending element. 
    
    long long n, k;
    cin >>  n >> k;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (long long i=0;i<n-1;i++){
        long long left=0, right=0, l_total=0, r_total=0;
        while (right<=i){
            while (right<=i && arr[left]+k>=arr[right]){
                right++;
            }
            right--;
            l_total=max(l_total, right-left+1);
            left++;
            right++;
        }

        left=i+1, right=i+1;
        while (right<n){
            while (right<n && arr[left]+k>=arr[right]){
                right++;
            }
            right--;
            r_total=max(r_total, right-left+1);
            left++;
            right++;
        }

        ans = max(ans, l_total+r_total);
    }
    cout << ans << endl;
}