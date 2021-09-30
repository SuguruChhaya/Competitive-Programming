#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
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
        /*
        if (i==1){
            cout << "";
        }
        */
        bool ok = true, moveL = true, moveR = true;
        long long l = i-1, r = i+1;
        while (ok){
            ok = false;
            long long prevL = l+1, prevR = r-1;
            bool lmoved = false, rmoved = false;
            while (moveL && l >= 0 && arr[l]>=arr[prevL]-currRadius){
                l--;
                ok = true;
                lmoved= true;
            }
            while (moveR && r <n && arr[r] <= arr[prevR]+currRadius){
                r++;
                ok = true;
                rmoved = true;
            }
            //!It can be false and can come back here and become true so no real point. 

            //*Reverse it since just easier that way. 
            if (lmoved==0){
                moveL = 0;
            }
            if (rmoved==0){
                moveR = 0;
            }
            currRadius++;
        }
        /*
        if (r-l-1==6){
            cout << "";
        }
        */
        result = max(result, r-l-1);
    }
    cout << result << endl;
}