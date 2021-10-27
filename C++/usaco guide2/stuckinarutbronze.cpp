#include <bits/stdc++.h>
using namespace std;

vector <long long> whenIntersect(long long i, long long j){

}

int main(){
    long long n;
    cin >> n;
    vector <tuple <char, long long, long long>> arr;
    for (long long i=0;i<n;i++){
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
    }
    bool ok = true;
    vector <bool> stopped(n, 0);
    vector <long long> ans(n, -1);
    long long large = 999999999999999;
    while (ok){
        ok = false;
        long long mini = large, stops;
        for (long long i=0;i<n;i++){
            for (long long j=i+1;j<n;j++){
                //*Either of them must be moving or else no intersection. 
                if (stopped[i]==0 || stopped[j]==0){
                    auto temp = whenIntersect(i, j);
                    if (temp[0] != -1 && temp[1]<mini){
                        stops = temp[1];
                        mini = temp[0];
                    }
                }
            }
        }
        for (long long i=0;i<n;i++){
            if (i==stops){
                //?Even after stopping, do I have to keep track of where the cow ended?
                
            }
        }
    }
}