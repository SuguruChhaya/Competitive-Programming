#include <bits/stdc++.h>
using namespace std;

int main(){
    //*I think I can just brute this one. 
    long long s, t;
    cin >> s >> t;
    long long result = 0;
    for (long long a=0;a<=s;a++){
        for (long long b=0;b<=s;b++){
            for (long long c=0;c<=s;c++){
                if (a==0 && b==0 && c==0){
                    cout << "";
                }
                if (a+b+c<=s && a*b*c<=t){
                    result++;
                }
            }
        }
    }
    cout << result << endl;
}