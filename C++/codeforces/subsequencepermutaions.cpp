#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Should I just brute force from k=1?
    //*Sort the string and see how many are in the space they should be. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        auto sorted = s;
        sort(sorted.begin(), sorted.end());
        long long result = 0;
        for (long long j=0;j<n;j++){
            if (sorted[j]!=s[j]){
                result++;
            }
        }
        cout << result << endl;
    }
}