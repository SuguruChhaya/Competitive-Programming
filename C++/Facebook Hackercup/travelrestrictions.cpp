#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=1;i<=t;i++){
        long long n;
        cin >> n;
        vector <char> I(n), O(n);
        for (long long j=0;j<n;j++){
            cin >> I[j];
        }
        for (long long j=0;j<n;j++){
            cin >> O[j];
        }
        vector <vector <char>> result (n, vector<char>(n, 'N'));
        for (long long j=0;j<n;j++){
            result[j][j] = 'Y';
            long long l = j-1, r=j+1;
            while (l>=0 && I[l]=='Y'&&O[l+1]=='Y'){
                result[j][l] = 'Y';
                l--;
            }
            while (r<n && I[r]=='Y'&&O[r-1]=='Y'){
                result[j][r] = 'Y';
                r++;
            }
        }
        cout << "Case #" << i << ":" << endl;
        for (auto v:result){
            for (auto e:v){
                cout << e;
            }
            cout << endl;
        }
    }
}