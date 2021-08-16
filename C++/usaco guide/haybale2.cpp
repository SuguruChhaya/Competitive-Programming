#include <bits/stdc++.h>

using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    vector <long long>differences;
    //*Index 0 will be difference between index1 - index2.
    //*So length will be n-1
    for (long long i=0;i<n-1;i++){
        differences.push_back(0);
    }
    //*Let's keep this thing 0-indexed. 
    for (long long i=0;i<k;i++){
        long long a, b;
        cin >> a >> b;
        if (a>=2){
            differences[a-2]++;
        }
        if (b-1<n-1){
            differences[b-1]--;
        }
        for (auto e:differences){
            cout << e << endl;
        }
    }
    //!Doing this, I will run into problems processing the first element. 
    //?How does the answer do it?
    vector <long long> arr;
    long long currTotal = 0;
    for (long long i=0;i<n;i++){
        currTotal+=differences[i];
        arr.push_back(currTotal);
    }

    sort(arr.begin(), arr.end());
    cout << arr[(n+1) / 2] << endl;

    for (auto e:arr){
        cout << e << endl;
    }
}