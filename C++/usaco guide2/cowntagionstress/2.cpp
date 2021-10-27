#include <bits/stdc++.h>
using namespace std;

bool allInfected(vector <long long> arr){
    //*Can only check from index 1.
    for (long long i=1;i<arr.size();i++){
        if (arr[i]<1){
            return false;
        }
    }
    return true;
}

int main(){
    long long n;
    cin >>n;
    vector <vector <long long>> arr (n+1);
    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    deque <pair <vector <long long>, long long>> q;
    vector <long long> temp (n+1, 0);
    temp[1] = 1;
    q.push_back({temp, 0});
    long long ans;
    while (!q.empty()){
        
        //cout << "running" << endl;
        auto curr = q[0];
        /*
        for (long long i=1;i<=n;i++){
            cout << curr.first[i] << endl;
        }
        */
        q.pop_front();
        if (allInfected(curr.first)){
            //!Since BFS method, as soon as we hit it, we should exit or else it will go on forever.
            ans = curr.second;
            break;
        }
        else{
            for (long long i=1;i<=n;i++){
                //*Basically look through all the 
                if (curr.first[i]!=0){
                    for (auto e:arr[i]){
                        auto temp = curr;
                        temp.first[i]--;
                        temp.first[e]++;
                        temp.second++;
                        q.push_back(temp);
                    }
                    curr.second++;
                    curr.first[i] *= 2;
                    q.push_back(curr);
                }
            }
        }
    }
    cout << ans << endl;
}