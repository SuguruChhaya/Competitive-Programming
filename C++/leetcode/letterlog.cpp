#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("a", "w", stdout);
    vector<string> logs = {"dig1 8 1 5 1","let1 art zero can","dig2 3 6","let2 own kit dig","let3 art zero"};

    vector<string>ans;
    vector<pair<vector<string>, string>> letter;
    vector<string>digit;
    for (auto e:logs){
        vector<string>arr;
        stringstream ss(e);
        string temp;
        while (getline(ss, temp, ' ')){
            arr.push_back(temp);
        }
        if ((int)(arr[1][0])<=57){
            digit.push_back(e);
        }
        else{
            pair<vector<string>, string>p;
            p.second = arr[0];
            for (long long i=1;i<arr.size();i++){
                p.first.push_back(arr[i]);
            }
            letter.push_back(p);
        }
    }
    sort(letter.begin(), letter.end());
    for (auto e:letter){
        string temp;
        temp += (e.second+' ');
        for (auto s:e.first){
            temp += (s+' ');
        }
        temp.pop_back();
        ans.push_back(temp);
    }
    for (auto e:digit){
        ans.push_back(e);
    }

    for (auto e:ans){
        cout << e << endl;
    }
}