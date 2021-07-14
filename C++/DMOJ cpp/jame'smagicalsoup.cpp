#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    //*Basically every soup has a time limit that it has to drunk by this time. 
    //*We could just sort the arr based on time available left. 
    //*I could use a sorted deque and remove until we reach limit. 
    //* I don't have to change time for all because I already know the current time. 
    //*Deque will store one long long only. 

    //!Basiscally there is a period range in which we have to drink. 
    //*Temperature is lower bound (cuz we have to wait a little) and freshness is lowerbound. 
    //*We can create an interval. 
    //!But we cannot just randomly assign because some intervals are more flexible than others so we wanna assign the less flexible ones first. 
    //*But that won't necessarily work all the time too. 
    //*Need a good fit in optimally. 
    //*One way is to deal with space with low demand first. 

    //!If level of demand is same then look at the length of the intervals there. 
    //*If short then prioratize because of less choices.
    //!Honestly, isn't there a brute force solution for this one?
    //*I cannot simulate every single drinking pattern because 500,000! could be the number of permutations.  
    long long x, n, t, f;
    cin >> x >> n;

    //*Create vector (extra for simple indexing):
    vector <vector <vector <long long >>> arr;
    for (long long i=0;i<=n;i++){
        arr.push_back({});
    }

    for (long long i=0;i<n;i++){
        cin >> t >> f;
        arr[]
    }

    //*Create the vector for every minute. 
    //*Information to store:
    //*For sorting: the demand. 
    //*Second argument: a vector of all the intervals. (later sort, set may eliminate duplicates. )
    /*
    deque <long long> queue;
    for (long long i=0;i<n;i++){
        cin >> t >> f;
        queue.push_back()
    }
    */

    //!First subtask: literally just generate all orders to drink and run a loop through them. 
    //*n must be like smaller than 15 in order for all permutations to even possibly work. 
    //!Let me try anyways. Won't use a hashset since it will take up too much memory.  
    
    //*If you can drink something early, drink it early. 
    //*The only permutation I really need is for when the starting time is the same. 



    for (long long )

}