#include <bits/stdc++.h>
using namespace std;

bool isOK(vector<long long> arr){
    long long prev = arr[0];
    for (long long i=1;i<arr.size();i++){
        if (arr[i]!=prev+1){
            return 0;
        }
        prev = arr[i];
    }
    return 1;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    //*Pointers: hard to debug
    deque<pair<vector<long long>, long long>> q;
    q.push_back({arr, 0});
    bool foundMin = 0;
    long long currMax;

    while (!q.empty()){
        auto curr = q[0];
        q.pop_front();
        if (isOK(curr.first)){
            if (!foundMin){
                cout << curr.second << endl;
                foundMin = 1;
            }
            currMax = curr.second;
        }
        else{
            for (long long i=curr.first[1]+1;i<curr.first[n-1];i++){
                auto temp = curr;
                temp.second++;
                temp.first.erase(temp.first.begin());
                temp.first.push_back(i);
                sort(temp.first.begin(), temp.first.)
            }
            /*
            auto it1  = curr.first.begin();
            it1++;
            auto it2 = curr.first.end();
            it2--;
            for (long long i=*(it1)+1;i<*(it2);i++){
                auto temp = curr;
                temp.second++;
                temp.first.erase(temp.first.begin());
                temp.first.insert(i);
                q.push_back(temp);
            }
            it2 = curr.first.end();
            it2--;
            for (long long i=*(it)-1;i>*(curr.first.begin());i--){
                auto temp = curr;
                temp.second++;
                temp.first.erase(temp.first.end());
                temp.first.insert(i);
            }
            */
        }
    }
}