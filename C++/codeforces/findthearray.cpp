#include <bits/stdc++.h>

using namespace std;

int main(){
    //*Finding the max length. 
    //!One pattern is that 1 must exist in all of the arrays. 
    //*Since if we reach down to 3, either 2 or 1 must exist. If we come down to 2, only 1 should exist. 

    //*Pretty simple: just keep adding 2 and then add the remaining. 
    
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long s;
        cin >> s;

        long long currAdd = 1;
        long long currTotal = 0;

        //*If equal or above, we want to go until we hit target or exceed. 
        long long result = 0;
        while (currTotal < s){
            currTotal += currAdd;
            currAdd += 2;
            result++;
        }

        cout << result << endl; 
    }
}