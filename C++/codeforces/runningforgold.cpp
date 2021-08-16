#include <bits/stdc++.h>
using namespace std;


//!I really cannot do a kachinukisen. 
//*I have to compare each of them to actually know. 
//!n^2 might work if I don't count duplicate pairs and if I keep a bool index array so if it is not possible, I know from the start. 


//!If there is more than such one athlete, print any of them.
tuple <vector <long long>, bool,  long long> which_wins(vector <long long> best_ranking, vector <long long> next, long long best_index, long long next_index){
    //*Order matters. Have to be ranked lower in the same marathon. 
    long long p1_wins = 0, p2_wins = 0;
    for (long long marathon=0;marathon<5;marathon++){
        if (best_ranking[marathon] < next[marathon]){
            p1_wins++;
            //!As soon as I hit 3 wins I could exit. 
            //*But since the loop is only 3, I don't think it would be a big difference...
            //!It could be 3, 0 but it could come back to 3, 2. So just because of 1 case cannot dictate the entire thing. 

        }
        else if (best_ranking[marathon] > next[marathon]){
            p2_wins++;

        }
    }
    //!I think I am misunderstanding the conditions here. 
    /*
    if (p1_wins >= p2_wins+3){
        return {best_ranking, 1, best_index};
    }
    else if (p2_wins >= p1_wins+3){
        return {next, 1, next_index};
    }
    */
    //*Even if it is equal, I still can just return p1. 
    //!Could there be difference based on which one I choose?
    
    if (p1_wins >= p2_wins){
        return {best_ranking, 0, best_index};
    }
    else{
        return {next, 0, next_index};
    }
    
}

int main(){

    //

    //!Need to be careful since arr is global. 
    //*Just pass it as parameter. 
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    //vector <long long> v;
    for (long long i=0;i<t;i++){
        //vector <vector <long long>> arr;
        long long n;
        cin >> n;
        //*Need to create a vector storing ranking positions of all. 
        //*0-index should be fine. 

        //!I think I can do comparison while reading in the data. 
        //*That means I don't have to store massive amounts of data and push back and stuff. 
        //*All I have to store is the rankings of current highest and the incoming from cin. 
        
        bool best_exists = true;
        long long result = 0;
        vector <long long> best_ranking;
        for (long long j=0;j<n;j++){
            //*Only 5 marathons. 
            vector <long long> temp;
            for (long long k=0;k<5;k++){
                long long rank;
                cin >> rank;
                temp.push_back(rank);
            }
            //arr.push_back(temp);
            //*If it is the first one, initualize the best_ranking. 
            if (j==0){
                best_ranking = temp;
            }
            else{
                //*the array of result is stored., 
                //!BUT, I DO need the index!!
                auto t = which_wins(best_ranking, temp, result, j);
                best_ranking = get <0> (t);
                best_exists = get <1> (t);
                result = get <2> (t);
                //*I can also return the correct array. 
                //!I have to return a tuple in this case. 
            }


        }

        //!If the length is one, there exists a best player: just the first one. 


        //*Just compare and store the max athlete.
        // 
        //*Starting from 0-th index upto n-2nd index. 
        /*
        for (long long p2=1;p2<n;p2++){
            auto temp = which_wins(arr, result, p2);
            //!Even if get equals, we still have to maintain the largest just in case a larger one appears later on. 
            //*I should return a pair: first says whether there is a win/loss. Second gives the value. 

        }
        */

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