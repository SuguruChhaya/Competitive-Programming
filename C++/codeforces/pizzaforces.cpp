#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Cannot do a DP/recursion solution because the number of friends could be super large.
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){

        //!I think it is some factor thingy.
        long long n;
        cin >> n;
        //*I think it would be OK to try dividing by 25 and dealing with the remainder. 
        long long result = n / 10 * 25;
        long long remainder = n % 10;
        if (remainder <= 6){
            result += 15;
        } 
        else if (remainder <= 8){
            result += 20;
        }
        else{
            result += 25;
        }

        cout << result << endl;

    }
}