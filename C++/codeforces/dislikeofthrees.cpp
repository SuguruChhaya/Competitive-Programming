#include <bits/stdc++.h>
using namespace std;



int main(){
    long long t;
    cin >> t;
    vector <long long> data;
    vector <long long> q;
    long long m = 0;
    while(t--){
        long long temp;
        cin >> temp;
        m = max(m, temp);
        q.push_back(temp);
    }
    long long curr =1;
    while (data.size()<m){
        string s = to_string(curr);
        char c = s[s.size()-1];
        if (curr % 3 ==0 || c=='3'){

        }
        else{
            data.push_back(curr);
        }
        curr++;
    }

    for (long long i=0;i<q.size();i++){
        cout << data[q[i]-1] << endl;
    }
}