#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    deque <long long> arr;
    while (q--){
        long long num;
        cin >> num;
        if (num==1){
            long long x;
            cin >> x;

            arr.push_back(x);
        }
        else if (num==2){
            cout << arr[0] << endl;
            arr.pop_front();
        }
        else{
            sort(arr.begin(), arr.end());
        }
    }
}