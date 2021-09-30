#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=1;i<=t;i++){
        long long n;
        string s;
        cin >> n >> s;
        long long ans = 0;
        for (long long a=0;a<n;a++){
            //*Substring can have len1
            for (long long b=a;b<n;b++){
                long long curr = a, temp=0;
                bool left = 0;
                while (curr<=b&&s[curr]=='F'){
                    curr++;
                }
                if (curr<=b){
                    if (s[curr]=='O'){
                        left=1;
                    }
                    for (long long c=a;c<=b;c++){
                        if (left&&s[c]=='X'){
                            left=0;
                            temp++;
                        }
                        else if (!left&&s[c]=='O'){
                            left=1;
                            temp++;
                        }
                    }
                }
                ans+=temp;
            }
        }
        cout << "Case #" << i << ": " << (ans % 10000007) << endl;

    }
}