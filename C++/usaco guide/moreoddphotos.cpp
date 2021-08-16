#include <bits/stdc++.h>
using namespace std;

vector <long long> arr = {0, 0};

bool can_make_group(long long curr){
    if (curr % 2==0){
        //*We are looking for even number. 
        if (arr[0] >= 1){
            return true;
        }
        else if (arr[1] >= 2){
            //*If we have 2 or more odds, we can make an even. 
            return true;
        }
        else{
            return false;
        }
    }
    else{
        //*Looking for odd. 

        if (arr[1] >= 1){
            return true;
        }
        //!Unlike even, we NEED an odd number to sum up to an odd number. 
        else{
            return false;
        }
    }
}


int main(){
    long long n;
    cin >> n;
    //!Create a size 2 array to check whether number is even or odd. 
    
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        //*First index is the #of evens and second is numodds 
        arr[temp % 2]++;
    }

    long long curr = 0;
    //*I can just return curr because that is essentially the number of groups I can make. 
    //*First we want an even (0)
    //*Have to check whether I can still make a group. 
    while (can_make_group(curr)){
        if (curr % 2==0){
            //*We are looking for even number. 
            if (arr[0] >= 1){
                arr[0]--;
            }
            else if (arr[1] >= 2){
                //*If we have 2 or more odds, we can make an even. 
                arr[1]-=2;
            }
        }
        else{
            //*Looking for odd. 

            if (arr[1] >= 1){
                arr[1]--;
            }
            //!Unlike even, we NEED an odd number to sum up to an odd number. 
            else{
                arr[0]-=2;
            }
        }

        curr++;
    }

    //*Only case I need to worry about is if there is an odd left. 
    curr -= arr[1];

    cout << curr << endl;
}