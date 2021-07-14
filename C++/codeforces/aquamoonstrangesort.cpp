#include <bits/stdc++.h>

using namespace std;

void countInversions(vector <long long> arr){
    long long result = 0;
    for (long long i=0;i<arr.size();i++){
        for (long long j=i+1;j<arr.size();j++){
            if (arr[i] > arr[j]){
                result++;
            }
        }
    }
    cout << result << endl;
}

int main(){
    //*Sounds like a bubble sort type algo. 
    //*If a right and left swap, then 
    //*Number of inversions??

    //*If it is related to inversion, then the fastest I can get is nlogn with inversion counting. 
    //!inversion is unrelated but rather the distance from the correct. 

    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> arr;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            arr.push_back(temp);
        }
        auto sorted = arr;
        sort(sorted.begin(), sorted.end());

        //*Instead of a map, I could keep a vector to show whether that location has been used already or not. 
        vector <bool> used;
        for (long long j=0;j<n;j++){
            used.push_back(0);
        }

        //*Stores all indexes for that specific number. 
        map <long long, vector <long long>> d;

        for (long long j=0;j<n;j++){
            if (d.count(sorted[j])==1){
                d[sorted[j]].push_back(j);
            }
            else{
                d.insert({sorted[j], {j}});
            }
        }

        for (long long j=0;j<n;j++){
            for (auto index: d[arr[j]]){
                if (used[index]==0 && )
            }
        }
    }

    //!Screw this problem C!!
}