#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    long long n, k, temp;
    cin >> n >> k;
    
    //*We could just store the extremes instead of having to go through all. 
    vector <long long> arr;
    /*
    long long mini=-1;
    long long maxi=-1;
    for (long long i=0;i<n;i++){
        cin >> temp;

        //*Add to vector. 
        if (mini==-1){
            mini = temp;
        }
        if (maxi==-1){
            maxi = temp;
        }

        //*After we have some valid mini and maxi, go into check. 
        if (abs(mini-temp)<=k && abs(maxi-temp)<=k){
            arr.push_back(temp);

            //*Update mini and maxi. 
            mini = min(mini, temp);
            maxi = max(maxi, temp);
        }
        //!We don't push back otherwise...

        //*I see there could be cases where it would be better to not distribute greedily.

    }
    */

    //!I think I could put them in array, sort them and check until one exceeds. 
    for (long long i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    long long result = 0;
    for (long long i=0;i<n;i++){
        //*Use while loop. 
        long long curr=0;
        long long j=i;
        //!j might go out of bounds. 
        while (j < n && arr[j]-arr[i]<=k){
            curr++;
            j++;
        }
        result = max(result, curr);
    }

    cout << result << endl;
}