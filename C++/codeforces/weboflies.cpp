#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    //*Cannot create an adjacency matrix so do a list I guess. 
    //*10^10 is too much space as well as time to create. 
    vector <set <long long>> arr;
    vector <bool> original_bool;
    //!1 index it so easier. 
    //*Create bool array.
    for (long long i=0;i<=n;i++){
        arr.push_back({});
        original_bool.push_back(1);
    }
    for (long long i=0;i<m;i++){
        long long u, v;
        cin >> u >> v;
        arr[u].insert(v);
        arr[v].insert(u);
    }

    long long q;
    cin >> q;
     
    
    for (long long i=0;i<q;i++){
        long long a;
        cin >> a;
        if (a==1){
            long long u, v;
            cin >> u >> v;
            arr[u].insert(v);
            arr[v].insert(v);
        }
        else if (a==2){
            long long u, v;
            cin >> u >> v;
            arr[u].erase(v);
            arr[v].erase(u);
        }
        else if (a==3){
            //*If the existing noble list is the same as previous noble list, that means we can exit the loop. 
            //!First copy the current state of the array since we need to reset it. 
            //auto copy = arr;
            auto curr = arr;
            //!I see for these conditions a do-while loop is better. 
            //*But I don't care. Just use a counter. 
            //long long counter = 0;
            //vector <set <long long>> prev;
            bool change_exists = true;
            auto bool_arr = original_bool;
            while (change_exists){
                change_exists = false;
                for (long long j=1;j<=n;j++){
                    if (curr[j].size()>0){
                        bool all_stronger = true;
                        for (auto f:curr[j]){
                            if (f<j){
                                all_stronger = false;
                                break;
                            }
                        }
                        //!Checking whether changes were made is pretty easy. 
                        //!I don't need to compare the entire array, 

                        if (all_stronger){
                            change_exists = true;
                            curr[j] = {};
                            bool_arr[j] = 0;
                            for (long long k=1;k<=n;k++){
                                //*Remove from set wherever possible. 
                                if (curr[k].count(j)==1){
                                    curr[k].erase(j);
                                }
                            }
                        }
                    }
                }
            }

            //*Exit so count the number of alive. 
            //!Just because the noble doesn't have any friends doesn't mean that he is dead. 
            //*Need a separate bool array for that. 
            long long num_alive = 0;
            
            for (auto e:bool_arr){
                //cout << e << endl;
                num_alive+=e;
            }
            //*Need to accomodate for the 1-index. 
            num_alive--;
            cout << num_alive << "\n";
        }
    }
}