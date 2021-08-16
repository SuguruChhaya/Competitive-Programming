#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Code it up in a different approach then.
    long long k, d;
    cin >> k >> d;
    vector <char> digits;
    for (long long i=0;i<d;i++){
        char temp;
        cin >> temp;
        digits.push_back(temp);
    }
    sort(digits.begin(), digits.end());
    //!If k==1, 0 is a valid solution. 
    if (digits[0]=='0' && digits.size()==1){
        cout << -1 << "\n";
    }
    else if (digits[0]=='0'){
        if (k<=2){
            string s;
            for (long long i=0;i<k;i++){
                s.push_back(digits[1]);
            }
            cout << s << "\n";
        }
        else{
            string s;
            s.push_back(digits[0]);
            for (long long i=2;i<k;i++){
                s.push_back(digits[1]);
            }
            s.push_back(digits[0]);
            cout << s << "\n";
        }
    }
    else{
        string s;
        for (long long i=0;i<k;i++){
            s.push_back(digits[0]);
        }
        cout << s << "\n";
    }
}