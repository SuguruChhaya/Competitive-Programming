#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    long long n;
    cin >> n;
    
    //!Ones that I can go directly are easy to consider but indirect is harder. 
    //*Rather than thinking how we can go from 1 station to another, I think it would be easier to say that this station receives from these other stations. 
    //*Then I could extend and process it using a queue. 

    vector <set <long long>> received;
    for (long long i=0;i<n+1;i++){
        received.push_back({});
    }

    for (long long i=0;i<n-1;i++){
        //*Direction is important. 
        long long a, b;
        cin >> a >> b;
        received[b].insert(a);
    }   

    //*Create a template bool arr with all false values initialized. 
    vector <bool> original_bool;
    for (long long i=0;i<n+1;i++){
        original_bool.push_back(0);
    }
    bool exists = false;
    for (long long station=1;station<=n;station++){
        auto bool_arr = original_bool;
        deque <long long> q = {station};
        while (!q.empty()){
            long long curr;
            curr = q[0];
            q.pop_front();
            //!There could be possible bi-directional nodes. 
            //!I guess what I can do is to check whether I already marked received=true for that node. 
            if (bool_arr[curr]==0){
                //*Change to true and iterate though all connected
                bool_arr[curr]=1;
                for (auto connected: received[curr]){
                    q.push_back(connected);
                }
            }
            
        }
        /*
        if (station==2){
            cout << "";
        }
        */
        bool ok = true;
        //*After all the marking, check whether all true. 
        for (long long check=1;check<=n;check++){
            if (bool_arr[check]==0){
                ok = false;
                break;
            }
        }
        if (ok){
            exists = true;
            cout << station << endl;
        }

    }
    if (exists==false){
        cout << -1 << endl;
    }
}