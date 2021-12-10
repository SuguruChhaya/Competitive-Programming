#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, e;
    cin >> n >> e;
    vector<long long> arr(n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
    }
    //*The index system is weird. 
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        for (long long k=1;k<=n;k++){
            if (i==1 && k==1){
                cout << "";
            }
            if (i==3 && k==1){
                cout << "";
            }
            if (i+e*k<=n){
                bool ok = true;
                set <long long> nums = {1};
                //!What if only 1 is left. 

                for (long long x=0;x<=k;x++){
                    nums.insert(arr[i+x*e]);
                    if (nums.size()>2){
                        ok = false;
                        break;
                    }
                    /*
                    else if (nums.size()==1){
                        if (*nums.begin()==1){
                            nums.insert(arr[i+x*e]);
                        }
                        else{
                            if (arr[i+x*e]==1){
                                nums.insert(arr[i+x*e]);
                            }
                            else{
                                ok = false;
                                break;
                            }
                        }
                    }
                    else if (nums.size()==2){
                        //Must be 1 and other number if we reach this point. 
                        if (arr[i+x*e]!=1){
                            ok = false;
                            break;
                        }
                    }
                    */
                }
                //!Even if there are only 2 numbers, the non-1 has to be a prime number. 
                
                if (ok && nums.size()==2){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}