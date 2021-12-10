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
    vector <long long> minElement(n+1);
    minElement[n] = 99999999999;
    for (long long i=n-1;i>=0;i--){
        minElement[i] = min(arr[i], minElement[i]);
    }
    vector <double> averages (n);
    double total = 0;
    for (long long i=n-1;i>=0;i--){
        total+=arr[i];
        averages[i] = (total-minElement[i]) / (n-i);
    }
    double maxAverage = 0;
    vector <long long> maxIndex;
    for (long long i=1;i<=n-2;i++){
        if (averages[i]>maxAverage){
            maxAverage = averages[i];
            maxIndex = {i};
        }
        else if (averages[i]==maxAverage){
            maxIndex.push_back(i);
        }
    }
    sort(maxIndex.begin(), maxIndex.end());
    for (auto e:maxIndex){
        cout << e << endl;
    }
}