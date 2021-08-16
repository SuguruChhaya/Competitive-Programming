#include <bits/stdc++.h>
using namespace std;

int main(){
    //*An easier way to think about it:
    //*All the elements out of order (sorted[i] doesn't match with original[i]) must be moved. 
    //*Now if it were 4, 3, 9, 7, we can sort this in 2 swaps. 
    //*However, since even the not-in-order elements are almost in order (largest element in left or smallest element in right)
    //*So we can only shift one by one. 
    //*EXCEPT the last move where I can get 2 of them right in one move. 
    //*SO number of not-in-place -1 is correct answer. 

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;    
        //*We don't know which one is the out of place one because could be increasing but still out of place. 
        arr.push_back(temp);
    } 

    auto sorted = arr;
    sort(sorted.begin(), sorted.end());

    long long differences = 0;
    for (long long i=0;i<n;i++){
        if (arr[i] != sorted[i]){
            differences++;
        }
    }
    differences--;
    long long zero = 0;
    cout << max(zero, differences) << endl;
}