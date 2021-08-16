#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    //!This problem seems pretty dar hard. 
    //!I think the naive way of thinking is that just buy all the stocks on the cheapest day and let it go on the most expensive day, 
    //*Does this work though? 
    sort(arr.begin(), arr.end());
    for (long long i=0;i<n;i++){
        if (i==0){
            cout << arr[i];
        }
        else{
            cout << " " << arr[i];
        }
    }
    cout << "\n";
    for (long long i=0;i<n;i++){
        if (i==0){
            cout << 'B';
        }
        else if (i==n-1){
            cout << 'S';
        }
        else{
            cout << 'E';
        }
    }
    cout << "\n";
}