#include <iostream>

using namespace std;

/*
int main(){
    //*There is actually a famous strategy...
    int x, y;
    cin >> x >> y;
    //*We can go once bu
    //*It was 6. Bro I'm getting my life back!!!

    //*Need to store the curr increment which is initally 1. 
    int curr = x;
    int curr_increment = 1;
    //*I don't need frequency. I can just 
    int prev = x;
    long long result = 0;
    //!Not guaranteed that we will reach right away so gotta do a forloop. 
    //*Store all the 1000 elements in a vector. 
    //?What's the point? Just iterate through the numbers one by one and check. 
    while (curr != y){  
        //*First check whether the curr increment is positive or not. 
        //!Also, we aren't moving the amount of the current increment but rather getting there. 
        //*Really, since we already know whether x is larger or y is larger, 
        //*But let me try finishing it manually. 

        //!At each while loop iteration, it really shouldn't matter if curr<y because we can still go the other way around. 
        //*We should just keep a mod counter. 
        if (curr<y){
            //*We have to move right
            //*Can use out of scope variable as well. 
            for (curr;curr<=x+curr_increment;curr++){
                //*Check whether we have reached. 
                //*First increment the distance then check whether reached or not. 
                result++;
                if (curr==y){
                    break;
                    //*Maybe turn on some counter
                }
            }
        }
        else{
            //*Since we passed through the loop, only case is curr>Y
            for (curr;curr>=)
        }
        curr += curr_increment;
        result += abs(prev-curr);
        prev = curr;
        curr_increment *= -2;
    }
}
*/

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x,y;
    cin >> x >> y;
    
    int curr = x;
    int curr_increment = 1;
    int counter =0;
    long long result = 0;
    while (curr !=y){
        if (counter % 2==0){
            //*Despite what I think curr actually doesn't increase. 
            //*I need a new variable. 
            //!My mistake since I want temp to stop at x+curr_increment, it should be <
            //*Should be OK to to do +1 since curr is not y at this point. 
            for (int temp=curr+1;temp<=x+curr_increment;temp++){
                result++;
                curr = temp;
                if (temp==y){
                    //*Have to reset curr even when we are breaking since we can break from bigger loop after. 
                    break;
                }//!Not incrementing properly.

            }
            
        }
        else{//!Actually, curr still stays at 2 so I need to change that too...
            for (int temp=curr-1;temp>=x-curr_increment;temp--){
                result++;
                curr = temp;
                if (temp==y){
                    break;
                }

            }
        }
        counter++;
        curr_increment*=2;
    }

    cout << result << "\n";
}