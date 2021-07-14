#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector <vector <long long>> arr;
    //*I need to print location so make it a 2D array. 
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back({temp, i+1});
    }

    sort(arr.begin(), arr.end());

    long long l=0;
    long long r = arr.size()-1;
    long long returned = false;
    //!Left cannot equal to right because it has to be 2 numbers. 
    while (l<r){
        if (arr[l][0]+arr[r][0]==x){
            returned = true;
            cout << arr[l][1] << " " << arr[r][1]<<"\n";
            break;
        }
        
        else if (arr[l][0]+arr[r][0]>x){
            r--;
        }
        else{
            l++;
        }
    }
    if (returned==false){
        cout << "IMPOSSIBLE" << "\n";
    }
}