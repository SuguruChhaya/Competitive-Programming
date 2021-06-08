#include <iostream>
#include <vector>
using namespace std;

//*I should actually try to create an object that stores all the connected nodes bruh. 
//*But since I need to recall from the first, I need to store in vector. 


int main(){
    //*TBH the easiest way I can think of is BFS through the edges. 
    //*But there should be a better way. 
    //*I could create a vector with all values. 
    //*Initialized with 1 but everytime mentioned increases by 1.
    //*But that only works for distance between 1. 
    //*Just try the BFS but probably TLE. 
    //!Not repeating itself must mean it is easier that way. 
    vector <vector<long long>> arr;
    //*Stores all the edges in a vector. 
    vector <long long> result;

    
    

    long long n, m, k;

    cin >>n >> m >> k;

    //*Initialize the vector. 
    //*For simplicity, create extra so start from 1 index. 
    for (long long i=1;i<=n+1;i++){
        arr.push_back({});
        result.push_back(0);
    }

    long long a, b;
    for (long long i=0;i<m;i++){
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    //!For every DP, I need to know the following information.
    //*The nodes I visited for a certain distance. 
    //!Just a feeling but for this type of info, I think recursion might be better to catch all the future values. 

    //*I think a possible way could be...
    //*Store array of all node objects for constant time access. 
    //*Even though the initial edges for all the nodes are the same, they continue to different distances. 

    //!I don't have a good idea on how to make this better...




    /*
    vector <bool> visited_or_not;
    //*Create extra space for this one too for consistency. 
    for (long long i=1;i<=n+1;i++){
        visited_or_not.push_back(false);
    }
    auto visited = visited_or_not;


    vector <vector <long long>> queue;
    vector <long long> curr;
    //!I feel like whenever we are checking, we could create a DP table that lists the values I will visit in the xth run. if X is already exists, add that in. If not, compute it using the latest info added in. 
    for (long long i=1;i<=n;i++){
        //*How do I know I reached k number of checks? Number of checks is the second argument.
        //!Based on the q, should be 0.  
        //*For the first item the came_from could be 0 because that will never be accessed. 
        queue = {{i, 0, 0}};
        visited = visited_or_not;
        //!Also cannot overlap so probably better to create a visited array for each. 
        while (queue.size() > 0){
            curr = queue[0];
            queue.erase(queue.begin());
            //!Just because one of them is out of range DOES mean everything is out of range. 
            if (curr[1]>k){
                break;
            }
            else if (visited[curr[0]]==false){
                result[i]+=1;
                visited[curr[0]] = true;
                for (long long j=0;j<arr[curr[0]].size();j++){
                    queue.push_back({arr[curr[0]][j], curr[1]+1}); //!Cannot go back to original (probably include a value as a came_from in the element)
                    
                }
            }
        }
        cout << result[i] << "\n";
    }
    //cout << "end";
    */
}