#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    //*Just create 5 arrays (or 2Dvector for 5 arrays)

    for (long long i=0;i<t;i++){
        //*I need to push back the rank and the index. 
        //*So I need a 3D vector. 
        vector <vector <vector <long long>>> arr;
        for (long long i=0;i<5;i++){
            arr.push_back({});
        }
        long long n;
        cin >> n;
        vector <long long> num_wins;
        for (long long j=0;j<n;j++){
            for (long long k=0;k<5;k++){
                long long rank;
                cin >> rank;
                arr[k].push_back({rank, j});
            }
            num_wins.push_back(0);
        }

        //*What if I sort inside an array??
        for (long long j=0;j<5;j++){
            sort(arr[j].begin(), arr[j].end());
        }
        //*Now create a counter array for all the participants. 
        bool found = false;
        for (long long j=0;j<5;j++){
            num_wins[arr[j][0][1]]++;
            if (num_wins[arr[j][0][1]] >=3){
                cout << arr[j][0][1] + 1 << "\n";
                found = true;
                break;
            }
        }
        //!I see. The athlete doesn't have to be superior in everything in order to win...
        //*The n^2 approach was more accurate. 
        if (found ==false){
            cout <<  -1 << "\n";
        }

        
        
    }
}