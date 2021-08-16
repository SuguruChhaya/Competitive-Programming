#include <bits/stdc++.h>
using namespace std;

int main(){
    //!I have to pick a good time to swap! 
    //*Do I HAVE to simulate?? (Because results could get really big).
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    
    long long k, n;
    cin >> k >> n;

    for (long long i=0;i<n;i++){
        long long x;
        cin >> x;

        long long lhs = 0, rhs = 0, timeused = 0;
        //*!Never stop until I return I guess. 
        for (long long currspeed = 1;;currspeed++){
            lhs += currspeed;
            timeused++;
            if (lhs+rhs >= k){
                cout <<  timeused << endl;
                break;
            }
            //!I was confused whether it should >x but even when we are at speed x, we reach there and decrease to that point. 
            //*So we pass it 2 times. 
            //!I guess the timeused++ works when exiting because 
            //*1. We don't have to finish at exact. 
            //*2. Even if x=5 and we have 3m left to run, well... we can just decrease it to 4 and run through. 
            //*3. If x=3 and we have 4m left to run, 
            //*If we have just been steadily increasing 1,2,3 and now we have 4m left, lhs+rhs >= k won't be satisfied just yet so we need 2 more seconds. 
            //*If we have already reached a max speed of say 5, we could just run an extra 4 meters earlier on since we covered all the way from 0m to 5m. 
            
            if (currspeed >= x){
                rhs += currspeed;
                timeused++;
                if (lhs + rhs >= k){
                    cout<< timeused << endl;
                    break;
                }
            }
        }
    }
}