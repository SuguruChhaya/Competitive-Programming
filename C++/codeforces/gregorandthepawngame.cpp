#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        //*OK is the fact that Gregor's pawns are in the n-th row relevant?
        //!Gregor's pawns cannot swap columns because enemy's pawns are only at the last place. 
        string enemy, gregor;
        cin >> enemy >> gregor;
        /*
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            enemy.push_back(temp);
        }
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            gregor.push_back(temp);
        }
        */
        long long result = 0;
        for (long long j=0;j<n;j++){
            if (gregor[j]=='1'){
                if (enemy[j]=='0'){
                    result++;
                }
                else if (j-1>=0 && enemy[j-1]=='1'){
                    result++;
                    enemy[j-1] = '0';
                }
                else if(j+1<n && enemy[j+1]=='1'){
                    result++;
                    enemy[j+1] = '0';
                }
            }
        }
        cout << result << "\n";
    }
}