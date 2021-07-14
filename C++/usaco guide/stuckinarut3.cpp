#include <bits/stdc++.h>
using namespace std;

struct Cow{
    long long time_stopped;
    long long x, y;
    char dir; 
};

long long infinity = 99999999999;
vector <Cow> cows;
//*Create a cow struct (which if I wanted I could do using tuples). 

long long n;


long long when_hits(long long i, long long j, long long current_time){

    //!The only issue with the previous one is that it cannot handle long long. 



    //*Create new cows instead of modify?
    Cow I = cows[i], J=cows[j];
    //*Why does it never hit if moving to same direction???
    //!All x coords and y_coords are different!! Would have made the question so much easier. 
    if (I.dir==J.dir){
        return infinity;
    }
    //!Honestly, I think it would be easier to create my own function and see if it works. 

    //!Also have to consider the fact that some points are already stopped. 
    //*However, even if they are stopped, they still leave a trail...


    //*If I had already stopped then return infinity. 
    //!Actually, I is always moving but not necessarily J. 
    //!Doesn't mean that if north then it isn't possible...

    //!Basically I have to consider whether N has passed through that or no. 
    if (I.dir=='N'){
        //*Swap could be an easy solution but I could create 2 numbers instead. 
        //!Think of a logical way to block out. 
        //!For future intersection, J must be still moving. 
        if (I.x >= J.x && I.y < J.y && J.time_stopped==infinity){
            vector <long long> intersect = {I.x, J.y};
            if (intersect[1]-I.y > intersect[0]-J.x){
                return current_time + intersect[1] - I.y;
            }
            
            
        }
        //!I.y < J.y is a must have. But I.x < J.x can still be considered. 
        else if (I.x < J.x){
            if (I.x >= J.x-current_time){
                //*The intersection point doesn't change. There is no longer competition since I can take its time and reach. 
                return current_time + J.y - I.y;
            }
        }
        return infinity;
    }
    else{
        //*I is going east and J is going north.  
        if (I.x < J.y && I.y >= J.y && J.time_stopped==infinity){
            vector <long long> intersect = {J.x, I.y};
            if (intersect[0]-I.x > intersect[1] - J.y){
                return current_time + intersect[0] - I.x;
            }
        }
        //!I.x < J.x is a must have. But I.y < J.y can still be considered. 

        //?Does current time ever become infinity? 
        //!I guess getting a negative value screws everything up...
        else if (I.y < J.y){
            if (I.y >= J.y -current_time){
                return current_time + J.x - I.x;
            }
        }

        return infinity;

    }
    //!Kind of confusing without the else. 


}

/*
int when_hits(int i, int j, int current_time)
{
  Cow I = cows[i], J = cows[j];
  if (I.dir == J.dir) return infinity; // never hits if moving same direction (or same cow)
  if (I.dir == 'E') { // assume without loss of generality that I is moving north, and J east
    swap (I.x, I.y); swap (J.x, J.y); 
  }
  if (J.y <= I.y) return infinity; // J isn't north of I?
  if (J.time_stopped == infinity) {
    if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return infinity; // No insersection, J still mooving
  } else {
    if (I.x > J.x || I.x < J.x - J.time_stopped) return infinity; // No intersection; j stopped already
  } 
  return current_time + J.y - I.y;
}
*/

long long advance_to_next_event(long long current_time){
    //*Loop through each of the cows and see what will happen. 
    //*Store the info in a vector. 
    vector <long long> events;
    long long minT=infinity;
    for (long long i=0;i<n;i++){
        events.push_back(infinity);
    }
    for (long long i=0;i<n;i++){
        if (cows[i].time_stopped==infinity){
            //*Checking all the cows that are still moving. 
            for (long long j=0;j<n;j++){
                
                if (current_time==2){
                    cout << "";
                }

                long long t = when_hits(i, j, current_time);
                //!There really is only one case of a negative number so I could go from there. 

                if (t < events[i]){
                    //? Will there ever be a time where it won't be smaller? I really don't think so..
                    //!Cuz I am looping through all the points so I do have to keep the minimum. 
                    events[i] = t;
                }
                
                
            }
            minT = min(minT, events[i]);

        }
    }

    if (minT==infinity){
        //?What does this really mean??
        //!This means that none of them will advance. 
        return infinity;
    }   

    for (long long i=0;i<n;i++){
        if (cows[i].time_stopped==infinity){
        if (cows[i].dir == 'N') cows[i].y += (minT - current_time);
        else                 cows[i].x += (minT - current_time);
        if (events[i] == minT) cows[i].time_stopped = minT;
            }
    }
    return minT;
}

int main(){
    
    cin >> n;
    //!If I anyways need to look for possible collisions, I think it would be easier to perfect the previous one. 

    //!Need to understand: http://www.usaco.org/current/data/sol_prob3_bronze_dec20.html

    

    //*Read all the data. 
    //*First create a bunch of cow objects and fill up the vector. 
    //!Initiailly I just push back the cow struct. 
    //*Hopefully no pointer errors etc. 
    
    for (long long i=0;i<n;i++){
        Cow temp;
        cows.push_back(temp);
    }

    for (long long i=0;i<n;i++){
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
        cows[i].time_stopped = infinity;
    }
    
    long long current_time = 0;
    //!In this case I think while and do while does the same thing. 
    while (current_time!=infinity){
        current_time = advance_to_next_event(current_time);
    }

    for (int i=0; i<n; i++)
        if (cows[i].time_stopped == infinity) cout << "Infinity\n";
        else                               cout << cows[i].time_stopped << "\n";
}