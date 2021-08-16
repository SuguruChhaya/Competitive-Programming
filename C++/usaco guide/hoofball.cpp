#include <bits/stdc++.h>
using namespace std;

/*
My code for solving this problem is below (in C++, but if you speak Java or Python it should hopefully still be easy to follow). I first wrote a helper function target(i) that computes to whom cow i passes the ball. Using this, I count for each cow i the number of cows passing to her. If this number is zero, the cow is a "source" -- she passes the ball away but never gets a ball back. Such cows all need their own starting ball from Farmer John.

The only other special case where Farmer John needs to distribute a ball initially is to a pair of adjacent cows that both pass to each-other, and where neither receives a pass from anyone else, so this pair is isolated from the rest of the game.
*/

int main(){
    long long n;
    cin >> n;
    vector <long long> arr;
    vector <bool> bool_arr; //!Marks whether a trap or not. 
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        bool_arr.push_back(0);
    }
    sort(arr.begin(), arr.end());


    long long result;
    //!Not the number of traps+1 but rather the number of not traps.

    //!But some special cases to consider: 1, 3, 4, 6, 7
    //*I have 2 consecutive blocks and there is only 1 block of non-trap but in reality I need 2. 
    for (long long i=0;i<n;i++){
        if (i==0 ){}
        else if (i==n-1){

        }
        //!If traps are consecutive, I can mark them and I can find the number of blocks. 
        else{
            //*Check whether I would rather go to previous that next. 
            if (abs(arr[i]) - abs(arr[i-1]) > abs(arr[i]) - abs(arr[i+1])){
                //*Not a trap. 
            }

        }
    }
}