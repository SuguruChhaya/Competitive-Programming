#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<string> arr(n);
    set<vector<vector<long long>>> curr;
    //*{{arr index, string index}, {arr indices we already visited}}
    set <long long> used;
    vector<bool> permanentlyUsed (n, 0);
    long long total = 0;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
        total+=arr[i].size();
    }
    sort(arr.begin(), arr.end());
    string ans = "";
    while (ans.size()!=total){
        if (curr.size()==0){
            long long i=0;
            while (arr[i][0]==arr[0][0]){
                if (!permanentlyUsed[i]){
                    curr.insert({{i, 0}, {i}});
                }
                i++;
            }
        }
        char mini = (int)'z' + 1;
        for (auto e:curr){
            mini = min(mini, arr[e[0][0]][e[0][1]]);
        }
        auto temp = curr;
        temp = {};
        for (auto e:curr){
            if (arr[e[0][0]][e[0][1]]==mini){
                if (e[0][1]+1==arr[e[0][0]].size()){
                    for (long long i=0;i<n;i++){
                        if (!used.count(i)){
                            auto tempE =e;
                            tempE[0] = {i, 0};
                            tempE[1].push_back(e[0][0]);
                            temp.insert(tempE);
                        }
                    }
                }
                else{
                    temp.insert({{e[0][0], e[0][1]+1}, e[1]});
                }
            }
        }
        if (temp.size()==1){
            for (auto e:(*(temp.begin()))[0]){
                ans += arr[e];
                permanentlyUsed[e]=1;
            }
            //*Also have to add the thing itself. 
            
            temp = {};
        }
        curr = temp;
    }
    cout << ans << endl;
}