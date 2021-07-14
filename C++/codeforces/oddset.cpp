#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        long long numOdds, numEvens;
        numOdds = numEvens = 0;
        for (long long j=0;j<2*n;j++){
            long long temp;
            cin >> temp;
            if (temp % 2==1){
                numOdds++;
            }
            else{
                numEvens++;
            }
        }
        if (numEvens==numOdds){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
}