#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, m;
        string s;
        cin >> n >> m >> s;
        vector <char> arr;
        for (auto c:s){
            arr.push_back(c);
        }

        //*Make sense to copy the vector. 
        for (long long j=0;j<m;j++){
            auto temp = arr;
            bool can_make = false;
            for (long long k=0;k<n;k++){
                if (arr[k]=='0'){
                    bool left = false, right = false;
                    if (k>0 && arr[k-1]=='1'){
                        //*A left element exists.
                        left = true; 
                    }
                    if (k<n-1 && arr[k+1]=='1'){
                        right = true;
                    }
                    //!I think my previous code failed because if index is 0 and arr[1] isn't '1', it keeps looking and seg error. 
                    //*New one should be fine. 
                    if (left && right){

                    }
                    else if (left || right){
                        //*If only left, change temp. 
                        temp[k] = '1';
                        can_make = true;
                    }
                }
            }
            if (can_make == false){
                break;
            }
            arr = temp;
        }
        for (auto x:arr){
            cout << x;
        }
        cout << endl;
    }
}