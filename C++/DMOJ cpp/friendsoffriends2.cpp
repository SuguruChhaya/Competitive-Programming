#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, q, temp, p1, p2;

    //*First create a rank and parent array with n+1 (why extra space?)
    //*I guess one issue might be that I always check in the dictionary whether it exists which costs time. 
    //*Create a separate rank and parent array?
    cin >> n >> q;

    //!I guess I just have to use 2 arrays since absolute value consumes too much time. 

    vector <long long> parent;
    auto rank = parent;

    //*I think the whole issue was finding in the dictionary took some time. 
    //*Because method of lookup was the same. 
    //*Create extra space for 1-indexing. 
    //!Try keeping my original negative. 

    for (long long i=1;i<=n+1;i++){
        parent.push_back(i-1);
        //*Initially, rank (how many it is carrying) is just 1. 
        rank.push_back(1);
    }
    

    for (long long i=0;i<q;i++){
        cin >> temp; 
        if (temp==1){
            cin >> p1 >> p2;

            //*I think I can simplify things here because no dictionary. 
            //!Continue unless the parent is itself.
            //!I forgot to consider that they may belong in the same parent! 
            while (parent[p1] != p1){
                p1 = parent[p1];
            }
            while (parent[p2] != p2){
                p2 = parent[p2];
            }
            //!I think I did it the opposite way which is super inefficient. 
            if (p1 != p2){
                if (rank[p1] > rank[p2]){
                    parent[p2] = p1;
                    rank[p1] += rank[p2];
                }
                else{
                    parent[p1] = p2;
                    rank[p2] += rank[p1];
                }
            }


        }
        else{
            cin >> p1;
            //!Problem is not with cin but uninitialized values. 
            while (parent[p1] != p1){
                p1 = parent[p1];
            }
            cout << rank[p1] << "\n";
        }
    }
    
}