#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> arr;
vector <long long> curr;
long long ans = 0;
void recursive(long long index){
    long long need = 0;
    for (auto e:arr[index]){
        if (curr[e]==0){
            need++;
        }
    }
    if (need==0){
        return;
    }
    long long currInfected = 1;
    //ans++;
    //!Since we already have one infected in the visiting farm
    while(currInfected<need){
        currInfected*=2;
        ans++;
    }
    for (auto e:arr[index]){
        if (curr[e]==0){
            ans++;
            recursive(e);
        }
    }
}

int main(){
    long long n;
    cin >> n;
    arr.resize(n+1);
    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    curr.resize(n+1, 0);
    curr[1] = 1;
    recursive(1);
    cout << ans << endl;
}