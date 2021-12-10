#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> types (n+1, -1);
    vector<bool> can2(n+1, 1);
    for (long long i=0;i<m;i++){
        char c;
        long long a, b;
        cin >> c>> a >> b;
        if (types[a]!=-1 && types[b]!=-1){
            if (c=='S'){
                if (types[a]!=types[b]){
                    cout << 0 << endl;
                    return 0;
                
                }
            }
            else{
                if (types[a]==types[b]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        else if (types[a]!=-1){
            if (c=='S'){
                can2[b] = 0;
                types[b] = types[a];
            }
            else{
                if (types[a]==0){
                    types[b] = 1;
                }
                else{
                    types[b] = 0;
                }
            }
        }
        else if (types[b]!=-1){
            if (c=='S'){
                can2[a] = 0;
                types[a] = types[b];
            }
            else{
                if (types[b]==0){
                    types[a] = 1;
                }
                else{
                    types[a] = 0;
                }
                can2[a] = 0;
            }
        }
        else{
            types[a] = 0;
            if (c=='S'){
                types[b] = 0;
            }
            else{
                types[b] = 1;
            }
            can2[b] = 0;
        }
    }
    long long num2 = 0;
    for (long long i=1;i<=n;i++){
        num2 += can2[i];
    }
    string s = "1";
    for (long long i=0;i<num2;i++){
        s.push_back('0');
    }
    cout << s << endl;
}