#include <bits/stdc++.h>
using namespace std;



pair <bool, long long> which_wins(vector <vector <long long>> arr, long long p1, long long p2){
    //*Order matters. Have to be ranked lower in the same marathon. 
    long long p1_wins = 0, p2_wins = 0;
    for (long long marathon=0;marathon<5;marathon++){
        if (arr[p1][marathon] < arr[p2][marathon]){
            p1_wins++;
            //!As soon as I hit 3 wins I could exit. 
            //*But since the loop is only 3, I don't think it would be a big difference...
        }
        else if (arr[p1][marathon] > arr[p2][marathon]){
            p2_wins++;
        }
    }
    if (p1_wins >= p2_wins+3){
        return {1, p1};
    }
    else if (p2_wins >= p1_wins+3){
        return {1, p2};
    }
    else{
        //*Even if it is equal, I still can just return p1. 
        if (p1_wins >= p2_wins){
            return {0, p1};
        }
        else{
            return {0, p2};
        }
    }
}

int main(){
    //!Need to be careful since arr is global. 
    //*Just pass it as parameter. 
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    //vector <long long> v;
    for (long long i=0;i<t;i++){
        vector <vector <long long>> arr;
        long long n;
        cin >> n;
        //*Need to create a vector storing ranking positions of all. 
        //*0-index should be fine. 
        for (long long j=0;j<n;j++){
            //*Only 5 marathons. 
            vector <long long> temp;
            for (long long k=0;k<5;k++){
                long long rank;
                cin >> rank;
                temp.push_back(rank);
            }
            arr.push_back(temp);
        }

        //!If the length is one, there exists a best player: just the first one. 

        bool best_exists = true;
        long long result = 0;
        //*Just compare and store the max athlete.
        // 
        //*Starting from 0-th index upto n-2nd index. 
        
        for (long long p2=1;p2<n;p2++){
            auto temp = which_wins(arr, result, p2);
            //!Even if get equals, we still have to maintain the largest just in case a larger one appears later on. 
            //*I should return a pair: first says whether there is a win/loss. Second gives the value. 
            best_exists = temp.first;
            result = temp.second;
        }

        if (best_exists){
            cout << result + 1 << "\n";
            //v.push_back(result+1);
        }
        else{
            cout << -1 << "\n";
            //v.push_back(-1);
        }
    }
    /*
    for (auto e:v){
        cout << e << endl;
    }
    */
}