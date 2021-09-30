#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i=1;i<=t;i++){
        long long n, result = 0, curr = 0;
        string w;
        cin >> n >> w;
        bool left = 0;
        while (curr<n && w[curr]=='F'){
            curr++;
        }
        if (curr!=n){
            if (w[curr]=='O'){
                left=1;
            }
            for (long long i=0;i<n;i++){
                if (left && w[i]=='X'){
                    result++;
                    left = 0;
                }
                else if (!left && w[i]=='O'){
                    result++;
                    left = 1;
                }
            }
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}