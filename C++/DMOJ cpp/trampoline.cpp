#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //!Not because of data type issue. 
    long long first_fib = 1;
    long long second_fib = 1;
    long long temp_first;
    vector <long long> arr = {2, 3};
    //!Either variables or some kind of numberical operation error. 
    for (long long  i=3; i<n+1; i++){
        //*Don't know if this is gonna work out like python
        temp_first = first_fib;
        first_fib = second_fib;
        second_fib = temp_first+second_fib;
        //first_fib, second_fib = second_fib, first_fib+second_fib;
        arr.push_back(second_fib % 2021 + i % 50);

    }

    vector <vector <long long>> queue = {{1,0}};
    vector <bool> seen;
    vector <long long> curr;
    for (int i=0;i<n;i++){
        seen.push_back(false);
    }

    while (queue.size() > 0){
        curr = queue[0];
        queue.erase(queue.begin());

        if (curr[0]==n){
            cout << curr[1];
            break;
        }
        //!I honestly think it is some data type issue. 
        else if (1<=curr[0] && curr[0]<=n && seen[curr[0]-1] == false){
            seen[curr[0]-1] = true;
            queue.push_back({curr[0]+1, curr[1]+1});
            queue.push_back({curr[0]-1, curr[1]+1});
            queue.push_back({curr[0]+arr[curr[0]-1], curr[1]+1});
            queue.push_back({curr[0]-arr[curr[0]-1], curr[1]+1});
        }
    }

}