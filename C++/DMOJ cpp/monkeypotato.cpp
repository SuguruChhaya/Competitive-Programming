#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k, d;
    cin >> k >> d;
    vector <char> digits;
    for (long long i=0;i<d;i++){
        char temp;
        cin >> temp;
        digits.push_back(temp);
    }
    //*really just overuse the smallest digit. 
    //*The only exception is probably when I am only given a 0. 
    sort(digits.begin(), digits.end());
    if (digits[0]=='0'){
        if (digits.size()==1){
            cout << -1 << "\n";
        }
        else{   
            if (k==1){
                cout << digits[1] << "\n";
            }           
            else{ 
                string s;
                //!I see for the first digit use the next smallest but for remaining just use 0. 
                //!But the string has to be a palindrome so even for the last digit I need a 0. 
                s.push_back(digits[1]);
                for (long long i=2;i<k;i++){
                    s.push_back(digits[0]);
                }
                s.push_back(digits[1]);
                cout << s << "\n";
            }
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