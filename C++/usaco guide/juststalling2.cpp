#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <long long> cow(n), stall(n);
    for (long long i=0;i<n;i++){
        cin >> cow[i];
    }
    for (long long i=0;i<n;i++){
        cin >> stall[i];
    }

    //*I totally understand this so implement the nlogn solution. 
    sort(cow.begin(), cow.end());
    sort(stall.begin(), stall.end());

    long long result = 1;
    long long cow_pointer=n-1, stall_pointer=n-1;
    //long long curr = 0;
    //*Really curr is just the distance from the end so I don't need this variable but for simplicity. 
    //!The condition is wrong. 
    while (cow_pointer>=0 && stall_pointer>=0){
        if (cow[cow_pointer]<=stall[stall_pointer]){
            //curr++;
            stall_pointer--;
        }
        else{
            //*Multiply
            result *= (n-1-stall_pointer) - (n-1-cow_pointer);
            cow_pointer--;
        }
    }
    //*Even when we run out of cow_pointer, we have to keep counting. 
    while (cow_pointer>=0){
        result *= n - (n-1-cow_pointer);
        cow_pointer--;
    }
    cout << result << endl;
}   