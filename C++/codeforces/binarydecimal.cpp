#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >>n;
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        int max_digit = 0;
        for (auto c:s){ 
            string temp;
            temp.push_back(c);
            
            max_digit = max(max_digit, stoi(temp));
        }
        cout << max_digit << endl;
    }
}