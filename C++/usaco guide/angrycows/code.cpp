#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long currRadius = 1;
    //bool ok = true;
    long long result =1;
    for (long long i=0;i<n;i++){
        currRadius = 1;
        if (i==4){
            cout << "";
        }
        bool ok = true;
        long long l = i-1, r = i+1;
        while (ok){
            ok = false;
            long long prevL = l+1, prevR = r-1;
            //!Basically it kept checking left so it started to extend. 
            
            while (l >= 0 && arr[l]>=arr[prevL]-currRadius){
                l--;
                ok = true;
            }
            while (r <n && arr[r] <= arr[prevR]+currRadius){
                r++;
                ok = true;
            }
            currRadius++;
        }
        if (r-l-1==6){
            cout << "";
        }
        
        result = max(result, r-l-1);
        if (result==4){
            cout << "";
        }
    }
    cout << result << endl;
}