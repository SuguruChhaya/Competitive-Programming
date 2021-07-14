#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    //*I could create a bool array to indicate the minimum and maximum???
    //!I think it would become helpful so I don't double count -1s that must
    vector <long long> arr;
    vector <bool> bool_arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        bool_arr.push_back(0);
    }

    //*The first day there was a breakout. 
    long long minimum = 0;
    for (long long i=0;i<n;i++){
        if (i==0){
            bool_arr[0] = true;
        }
        else if (arr[i]!=-1){
            bool_arr[i-1] = true;
        }
    }
    for (long long i=0;i<n;i++){
        minimum+=bool_arr[i];
    }

    //*Now consider all the uncertain cases. 
    //!If that day was already taken, there really is no point covering that day again. 
    //*Should cover a day that hasn't yet been covered if possible. 
}