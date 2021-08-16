#include <bits/stdc++.h>

using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    vector <long long>differences;
    //*Index 0 will be difference between index1 - index2.
    //*So length will be n-1
    for (long long i=0;i<n+1;i++){
        //*Why create an n+1 size array?
        differences.push_back(0);
    }

    for (long long i=0;i<k;i++){
        long long a, b;
        cin >> a >> b;
        differences[a]++;
        differences[b+1]--;
    }
    vector <long long> data;
    long long currVal = 0;
    for (long long i=0;i<n;i++){
        currVal+=differences[i];
        data.push_back(currVal);
    }

    sort(data.begin(), data.end());


    cout << data[n/2] << endl;
}