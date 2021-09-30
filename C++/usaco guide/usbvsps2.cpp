#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long m;
    cin >> m;
    vector <pair <long long, string>> arr (m);
    for (long long i=0;i<m;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    long long num=0, cost = 0;
    for (long long i=0;i<m;i++){
        if (arr[i].second=="USB" && a>0){
            a--;
            num++;
            cost+=arr[i].first;
        }
        else if (arr[i].second=="PS/2" && b>0){
            b--;
            num++;
            cost+=arr[i].first;
        }
        else if (c>0){
            c--;
            num++;
            cost+=arr[i].first;
        }
    }
    cout << num << " " << cost << endl;
    
}