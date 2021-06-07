#include <iostream>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;
int main() {
    
    ifstream fin("teleport.in");
    
    ofstream fout("teleport.out");
    
    int x, y, a, b;
    fin >> a >> b >> x >> y;
    /*
    set <int> visited;
    //Apparantly there is an issue with constructability or assignability. 
    vector<vector <int>> queue;
    vector<int> start = {a, 0};
    queue.push_back(start);
    vector<int> curr = start;
    int result=0;
    bool used = false;
    //Close but missing something

    //Passed the first testcase but nothing else. 
    //I cannot just set used=true because if a non-teleported solution gets chosen,i
    while (!queue.empty()){
        
        curr = queue[0];
        //I am getting errors when I try to erase the first element of a vector with the next line. 
        //The function in itself has no problem. I just failed to add items to the queue. 
        //Store in a tuple or array or something along with the value. 
        queue.erase(queue.begin());
        if (curr[0] == b){
            break;
        }
        //!The individual results shouldn't be based off how many times I looped through. 
        //*Let the second value just be the amount. 
        //Check whether the hashset includes the element or not. 
        //Actually, this works. 
        if (visited.find(curr[0]) == visited.end()){
            visited.insert(curr[0]);
            //Create 2 temporary vectors. 
            vector <int> temp1 = {curr[0]+1, curr[1]+1};
            queue.push_back(temp1);
            vector <int> temp2 = {curr[0]-1, curr[1]+1};
            queue.push_back(temp2);
            if (curr[0] == x){
                vector <int> temp = {y, curr[1]};
                queue.push_back(temp);   
                //In the best case scenario, I will only use the teleportation once. 
                //result--;
                
            }
            else if (curr[0] == y){
                vector <int> temp = {x, curr[1]};
                queue.push_back(temp);
                //result--;
                

            }
        }
        
    }
    
    //fout << curr[1];
    */
    //!Kind of dumb that I didn't come up with the easier solution of only 3 cases. 
    int answer;
    //*C++ min can only contain 2 arguments. 
    answer = min(abs(b-a), abs(x-a) + abs(y-b));
    answer = min(answer, abs(y-a) + abs(x-b));
    fout << answer;
    

    //I guess the first thing I should do is to determine whether the teleportation is worth it or not. 
    /*
    int smaller, larger;
    smaller = min(x, y);
    larger = max(x, y);
    if (a == b){
        fout << 0;
    }

    //Another case is when the teleportation is to its same place or only distance 1. 
    else if (abs(x-y) <= 1){
        fout << 0;
    }
    else if (a < b){
        if (a <=smaller<)
    }

    else if (a > b){

    }
    */

    //Honestly, I think I could just do a BFS checking whether I have visited yet. 


    //*I am having trouble understanding how to find whether it exists. 
    //*I need to consider 2 factors:
    //1. I am gonna look into a c++ set. Probably better to get used to that. 
    //2, I am gonna 

}
    
