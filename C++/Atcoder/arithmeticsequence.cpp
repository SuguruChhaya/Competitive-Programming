#include <bits/stdc++.h>
using namespace std;

/*
Instead of trying to think about the problem in terms of minimizing the amount of time needed to accomplish a certain distance, we can flip the problem around - if Bessie can run for T seconds and she wants to be running no more than X meters per second at the end of the T seconds, what is the furthest distance she can run?

Intuitively, we want her speed to be as high as possible throughout her run. If there were no speed cap at the end, Bessie would consistently increase her speed every second. Because of the presence of the speed cap though, Bessie may need to switch from speeding up to slowing down in order to meet the requirement of traveling no more than X meters per second at the end.

As a result, for a given speed V, Bessie will be traveling at that speed for at most 2 seconds - 1 second when she is speeding up, and one second when she is slowing down. We can therefore simulate Bessie's fastest possible run subject to her starting at 0 meters per second and ending with speed no more than X meters per second as follows - we will track Bessie's distance traveled while she is speeding up and while she is slowing down. We will increment Bessie's speed starting at 1 meter per second until she has traveled enough distance to finish the race. Increment Bessie's distance covered while speeding up by this speed, and check if Bessie's total distance traveled exceeds K meters. If the distance has not been exceeded, and Bessie could travel at this speed while slowing down, then increment Bessie's distance covered while slowing down by this speed, and perform the total distance check again.

The moment in time when Bessie's theoretical maximum distance traveled exceeds K meters is the desired answer. It is worth noting that following this specific strategy of speeding up and slowing down may not actually meet the race conditions properly, but it is always possible to construct a strategy that covers exactly the given distance in the asserted time.

There is one final concern - is simulating this one second at a time fast enough? The worst possible case here is where Bessie needs to run 109 meters and she must end the race running at 1 meter per second. In this case, it takes 63245 seconds. Performing one thousand of these simulations should therefore run in time comfortably.
*/

int main(){
    //*If changing the middle one then the entire arithmetic just flips around. 
    //!NEED to do some math. 
    //!Then there is the actual distance I need to travel. 
}