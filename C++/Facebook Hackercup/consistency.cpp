#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=1;i<=t;i++){
        string s;
        cin >> s;
        long long result = 9999999999999;
        set <char> vowels = {'A', 'E', 'I', 'O', 'U'};
        for (long long a=0;a<26;a++){
            long long temp = 0;
            for (long long b=0;b<s.size();b++){
                if (s[b]!=(char) ((int) ('A') +a)){
                    if (vowels.count(s[b])==1){
                        if (vowels.count((char) ((int) ('A') + a))==1){
                            temp+=2;
                        }
                        else{
                            temp++;
                        }
                    }
                    else{
                        if (vowels.count((char) ((int) ('A') + a))==1){
                            temp++;
                        }
                        else{
                            temp+=2;
                        }
                    }
                }
            }
            result = min(result, temp);
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}