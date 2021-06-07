#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    for (int i=0;i<s.size();i++){
        if (s[i] == '6'){
            cout << '9';
        }
        else if (s[i]=='9'){
            cout << '6';
        }
        else{
            cout << s[i];
        }
    }

}