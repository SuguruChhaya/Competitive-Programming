#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Do until I understand. 
    long long n, t;
    cin >> n >> t;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long left=0, right=0, curr=0, ans=0;
    while (left<n && right<n){
        curr+=arr[right];
        right++;

        if (curr>t){
            right--;
            curr-=arr[right];
            if (right-left>ans){
                cout << "";
            }
            
            curr-=arr[left];
            left++;
        }
        else{
            //!Cannot check right after right is incremented but after making sure it isn't larger. 
            ans = max(ans, right-left);
        }
        
    }
    //*Check even after I exit the loop. 
    cout << ans << endl;
}