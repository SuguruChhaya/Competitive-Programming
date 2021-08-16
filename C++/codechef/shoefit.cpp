#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long a, b, c;
        cin >> a >> b >> c;
        vector <long long> arr = {0, 0};
        arr[a]++;
        arr[b]++;
        arr[c]++;

        if (arr[0]>=1 && arr[1]>=1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}