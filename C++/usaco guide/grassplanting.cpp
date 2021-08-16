#include <bits/stdc++.h>
using namespace std;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    long long n;
    cin >> n;
    
    //*Create a nxn adjacency matrix.
    //!Create it as 1 index. 

    //*Because it is a 10^5, I guess an adjacency list will be better. 
    //vector <vector <bool>> bool_arr; 
    vector <set <long long>> adjacency;
    for (long long i=0;i<n+1;i++){
        adjacency.push_back({});
    }

    //!Possible optimizations:
    //*Adjacency list is symmetric. 
    //!Do I have to do the while loop all the time or is there a way to store. 
    //!Unordered set doesn't do much. 
    
    for (long long i=0;i<n-1;i++){
        long long a, b;
        cin >> a >> b;
        adjacency[a].insert(b);
        adjacency[b].insert(a);
    }

    vector <set <long long>> set_arr;
    for (long long i=0;i<n+1;i++){
        set_arr.push_back({});
    }

    long long maxTypes = 1;
    for (long long field = 1;field<=n;field++){
        long long type=1;
        while (set_arr[field].count(type)==1){
            type++;
        }
        maxTypes = max(maxTypes, type);
        set <long long> direct_neighbors;
        
        for (auto direct:adjacency[field]){
            set_arr[direct].insert(type);
            direct_neighbors.insert(direct);
        }
        /*
        for (long long direct=1;direct<=n;direct++){
            //!Bool arr is a 2D array. 
            if (bool_arr[field][direct]==1){
                set_arr[direct].insert(type);
                direct_neighbors.insert(direct);
            }
        }
        */

        for (auto direct:direct_neighbors){
            for (auto indirect:adjacency[direct]){
                set_arr[indirect].insert(type);
            }
        }
        /*
            for (long long indirect = 1;indirect<=n;indirect++){
                //cout << direct << " " << indirect << endl;
                if (bool_arr[direct][indirect]==1){
                    set_arr[indirect].insert(type);
                }
            }
        }
        */


    }
    cout << maxTypes << endl;
}