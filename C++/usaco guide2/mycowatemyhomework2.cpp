#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    double maxAverage = 0;
    vector <long long>maxIndex;
    for (long long k=1;k<=n-2;k++){
        vector <long long> temp;
        for (long long i=k;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        double total = 0;
        for (long long i=1;i<temp.size();i++){
            total+=temp[i];
        }
        double average = total / temp.size();
        if (average > maxAverage){
            maxAverage = average;
            maxIndex = {k};
        }
        else if (average==maxAverage){
            maxIndex.push_back(k);
        }
    }
    for (auto e:maxIndex){
        cout << e << endl;
    }
}