#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    long long n;
    cin >> n;

    //*Basically, I just add it to the number of edges from every single and find max. 
    vector <long long> arr;
    for (long long i=0;i<n+1;i++){
        arr.push_back(0);
    }

    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b]++;
    }

    long long maxi = 0;
    for (auto e:arr){
        maxi = max(maxi, e);
    }

    cout << maxi+1 << endl;

}