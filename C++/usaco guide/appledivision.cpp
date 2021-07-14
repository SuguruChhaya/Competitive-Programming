#include <bits/stdc++.h>

using namespace std;

int main(){
    //*One apple either goes to one or the other so I can create queue to deal with that. 
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    deque <vector <long long>> q = {{0, 0, 0}};
    vector <long long> curr;
    //*Information: index, 1st pile, 2nd pile. 
    long long result = 99999999999999999;
    while (!q.empty()){
        curr = q[0];
        q.pop_front();
        if (curr[0]==n){
            result = min(result, abs(curr[1]-curr[2]));
        }
        else{
            q.push_back({curr[0]+1, curr[1]+arr[curr[0]], curr[2]});
            q.push_back({curr[0]+1, curr[1], curr[2]+arr[curr[0]]});
            
        }
    }
    cout << result << endl;
}

//*Interesting I could also exploit the bit manipulation of an object to represent permutation. 
//*Could use "next_permutation" but more used to processing in a queue. 

//*Bitmask: I could learn this sometime soon. 