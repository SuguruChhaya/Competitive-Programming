#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    long long n;
    cin >> n;
    //!TLE anyways + wrong answer. 
    //0-> Bessie, 1-> Elsie
    vector <long long> arr (2*n+1, 0);
    vector <long long> elsie;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        elsie.push_back(temp);
        arr[temp]=1;
    }
    vector <long long> bessie;
    //?Is this loop counter even correct?
    for (long long i=1;i<=2*n;i++){
        if (!arr[i]){
            bessie.push_back(i);
        }
    }
    //*For every elsie, we can binary search the smallest value of bessie that is larger

    long long ans = 0;
    //!Have to be careful with the value I set for OK. 
    for (auto e:elsie){
        long long l = 0, r = n-1;
        long long ok=-1;
        while (l<=r){
            long long mid = (l+r) / 2;

            if (bessie[mid]<e){
                //*Bessie is still smaller
                l = mid+1;
            }
            else{
                //*Bessie is larger. 
                ok = mid;
                r = mid-1;
            }
        }
        if (ok==-1){
            //*Nothing works
            continue;
        }
        while (ok < n && arr[bessie[ok]]){
            ok++;
        }
        if (ok<n){
            //*Could find a winning one.
            //!Shouldn't this bessie[ok]? 
            //cout << "Winning: " << bessie[ok] << endl;
            ans++;
            arr[bessie[ok]] = 1;
        }
    }
    cout << ans << endl;
}