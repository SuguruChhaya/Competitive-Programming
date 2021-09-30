#include <bits/stdc++.h>
using namespace std;

//!A subarray can be represented as difference of 2 prefixes is important concept. 
int main(){
    //!Even when I change my approach, I get WA on the cases with negative numbers. 

    long long n;
    cin >> n;
    vector <long long> arr;
    long long prev = 0;
    map <long long, long long> d = {{0, 1}};
    //!Realistically, I probably won't come up with a clever way to account for negatives. 
    //M[(psums % N + N) % N]++;
    //*I could first create array and then change. 
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        //!I need to account for negative sums. 
        prev += temp;
        //arr.push_back(prev);
        arr.push_back(prev);
    } 
    //*Really similar to previous problem except that I need to build a subarray of mods I guess. 

    for (long long i=0;i<n;i++){
        arr[i] = ((arr[i] % n)+n)%n;
        d[arr[i]]++;
    }
    /*
    for (long long i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    */
    
    long long result = 0;
    //*If 0 comes up then the entire prefix works. 
    for (auto p:d){
        result += (p.second) * (p.second-1) / 2;
    }
    cout << result << endl;

    //!I think the easier way to think about this problem is to think of it as the relative distance. 
    //*If the distance is a multiple of n then it is OK.
    //*Can't I add n to move it up and then mod it?
    //!But we don't know how many times we want to add!
    //*Basically by % once, we get a shortcut and then we just have to add again and then mod to get it above 0. 
    
}