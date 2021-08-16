#include <bits/stdc++.h>
using namespace std;

long long which_wins(vector <vector <long long>> arr, long long p1, long long p2){
    long long p1_wins = 0, p2_wins = 0;
    for (long long marathon = 0;marathon<5;marathon++){
        if (arr[p1][marathon] < arr[p2][marathon]){
            p1_wins++;
            if (p1_wins>=3){
                return p1;
            }
        }
        else if (arr[p1][marathon] > arr[p2][marathon]){
            p2_wins++;
            if (p2_wins>=3){
                return p2;
            }
        }
    }

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        vector <vector <long long>> arr;
        long long n;
        cin >> n;
        vector <bool> could_be;
        for (long long j=0;j<n;j++){
            //*Only 5 marathons. 
            vector <long long> temp;
            for (long long k=0;k<5;k++){
                long long rank;
                cin >> rank;
                temp.push_back(rank);
            }
            arr.push_back(temp);
            could_be.push_back(1);
        }

        //!I need to realize that there is no tie. 
        //!So among two pairs, a winner will always exist. 

        //*Initial start off is important.

        //!best_exists is going to be turned true when an answer is found. 
        //*I am gonna use the bool in a different way compared to previous. 
        long long result = 0;
        bool best_exists = false;
        for (long long p1=0;p1<n;p1++){
            if (could_be[p1]==true){
                bool could_be_p1 = true;
                //!If I cancel out, those that cannot be cannot contribute by markings. 
                //!If there is even a hint of possibility, I guess I could loop through everything. 
                
                for (long long p2=0;p2<n;p2++){
                    //*First check the bool arr. 
                    //!Cannot check the same number because then we will get 0, 0 and nothing will return. 
                    if (p1!=p2){
                        auto winner = which_wins(arr, p1, p2);
                        //*If the winner is p2, we can quit the p1. 
                        //*If the winner is p1, mark p2 as not possible and go on. 
                        if (winner==p1){
                            could_be[p2] = false;
                        }
                        else{
                            could_be_p1 = false;
                            break;
                        }
                    }
                }
                //!Just because it won against 
                if (could_be_p1){
                    cout << p1 + 1 << "\n";
                    best_exists = true;
                    break;
                }
            }
        }
        if (best_exists==false){
            cout << -1 << "\n";
        }
    }

}