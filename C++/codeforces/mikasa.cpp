#include <bits/stdc++.h>
using namespace std;

int main(){
    //*There is some kind of pattern but I need to examine more carefully. 
    //*Make a brute force to that first. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, m;
        cin >> n >> m;
        for (long long j=0;j<=m;j++){
            cout << (n ^ j) << endl;
            //*Based on the example of 69 and 696, it is not true that it goes down by 4. In fact, the 69, 696 testcase was going down by 2. 
            //!There is mostly one type of movement and it is replicating in the small scale as well as the big scale. 

            //!Different patterns for different numbers. 
            //*What if during mid-pattern, I reach zero?
            
        }
    }
}