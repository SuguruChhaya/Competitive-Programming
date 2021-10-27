#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> arr;
vector <long long> ans;
/*
void recursive(long long i, long long original){
    for (auto e:arr[i]){
        ans[original]++;
        recursive(e, original);
    }
}
*/

long long recursive(long long i){
    if (ans[i]==-1){
        //*We start off from the number of direct subordinates. 
        long long temp = arr[i].size();
        for (auto e:arr[i]){
            temp+=recursive(e);
        }
        ans[i] = temp;
        
    }
    //!It will never return -1
    return ans[i];
}

int main(){
    long long n;
    cin >> n;
    arr.resize(n+1);
    ans.resize(n+1, -1);
    for (long long i=2;i<=n;i++){
        long long a;
        cin >> a;
        arr[a].push_back(i);
    }
    for (long long i=1;i<=n;i++){
        recursive(i);
    }
    for (long long i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}