#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Probably run out of time and space but my only idea is to store in a vector and add to vector then sort it and get the second.
    //*But this will cause n^2 time. I think a set automatically is sorted so I can make sure duplicates are included and use iterator from the end. 

    long long n;
    cin >> n;
    long long x, y;
    vector <vector <long long>> arr;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        arr.push_back({x, y});
    }
    /*
    vector <long long> final_arr;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            final_arr.push_back(max(abs(arr[i][0]-arr[j][0]), abs(arr[i][1]-arr[j][1])));
        }
    }
    */
    set <pair <long long, string>> hashset;
   
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            //hashset.push_back(max(abs(arr[i][0]-arr[j][0]), abs(arr[i][1]-arr[j][1])));
            //*Is there some kind of hashing that will guarantee there won't be duplicates?
        }
    }

    //sort(final_arr.begin(), final_arr.begin());
    
}