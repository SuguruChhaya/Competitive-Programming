#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("a.in", "r", stdin);
    freopen("a", "w", stdout);
    long long t;
    cin >> t;
    for (long long i=1;i<=t;i++){
        long long n;
        cin >> n;
        vector <string> arr (n);
        for (long long j=0;j<n;j++){
            cin >> arr[j];
        }
        long long large = 999999999999;
        //vector <long long> result = {large, large};
        pair <long long, set <set <vector <long long>>>> result;
        result.first = large;
        for (long long row = 0;row<n;row++){
            bool ok = true;
            long long temp = 0;
            set <vector <long long>> s;
            for (long long col = 0;col<n;col++){
                if (arr[row][col]=='O'){
                    ok = false;
                    break;
                }
                else if (arr[row][col]=='.'){
                    temp++;
                    s.insert({row, col});
                }
            }
            if (ok){
                if (result.first==temp){
                    result.second.insert(s);
                }
                //!I need to make sure it is smaller!
                else if (temp <result.first){
                    result = {temp, {s}};
                }
            }
        }
        for (long long col = 0;col<n;col++){
            bool ok = true;
            long long temp = 0;
            set <vector <long long>> s;
            for (long long row = 0;row<n;row++){
                if (arr[row][col]=='O'){
                    ok = false;
                    break;
                }
                else if (arr[row][col]=='.'){
                    temp++;
                    s.insert({row, col});
                }
            }
            if (ok){
                if (result.first==temp){
                    result.second.insert(s);
                }
                else if (temp <result.first){
                    result = {temp, {s}};
                }
            }
        }

        cout << "Case #" << i << ": ";
        if (result.second.size()==0){
            cout << "Impossible";
        }
        else{
            cout << result.first << " " << result.second.size();
        }
        cout << endl;
    }
    //Case 5 and 8 are incorrect. 
    //!I need to keep a set of all the cell types. 
    //
}