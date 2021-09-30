#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("photo.in","r",stdin);
	//freopen("photo.out","w",stdout);
    long long n;cin >> n;
    vector <long long> arr (n-1);
    vector <bool> used (n+1);
    //!I get how we never have to do all simulations because if the first one is 1, there is only one valid permutaion based on sums. 
    //*We can just check whether they are in bounds and don't repeat. 
    //*Is O(N) solution possible tho? 
    //!If the first one changes, the remaining behaviour is predictable for sure.
    //*But I still have to check whether there are no duplicates or all in range right? 

    //*Really curious about O(n). Found pattern but don't know what to dowith it. 
    for (long long i=0;i<n-1;i++){
        cin >> arr[i];
    }
    vector <long long> ans(n);

    for (long long a=1;a<=n;a++){
        ans[0] = a;
        for (long long i=1;i<n;i++){
            ans[i] = arr[i-1] - ans[i-1];
        }
        for (long long i=1;i<=n;i++){
            used[i] = 0;
        }
        bool bad = 0;
        for (long long i=0;i<n;i++){
            if (ans[i] <= 0 || ans[i]>n || used[ans[i]]){
                bad = 1;
                break;
            }
            used[ans[i]] = 1;
        }
        if (!bad){
            for (long long i=0;i<n;i++){
                cout << ans[i];
                if (i<n-1){
                    cout << " ";
                }
                
            }
            cout << endl;
            break;
        }
    }
}