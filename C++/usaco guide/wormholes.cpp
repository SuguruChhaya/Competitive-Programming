#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Not that only if 2 holes with the same x-values are paired then it will be stuck. 
    //*That is definitely the case but it could be the case if there is a diagonal. 
    //*Then how do I test??
    //!For each one I could run a simulation testing the cows starting from all the coordinates. 
    //*If I end up reaching the starting coordinate, I am stuck in a cycle. 
    //*Wormhole coordinates can only be integers but starting coordinates don't have to be so I could start from all coordinates. 

    long long n;
    cin >> n;

    vector <vector <long long>> coords;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }

    //*What information do I have to store?
    //*The complete pairing can be stored in a vector <vector<vector<long long>>. Though there may be reverse, I don't think it will take up so much time.     
    //*Each pairing can be stored in a vector < vector <vector <long long>>>. The first is vector surrounds all pairs. The second surrounds one pair. The 3rd surrounds one point (x, y) 
    //*I think it would take less time erasing the elements rather than checking whether it has already been used???
    //*The remaining points will be stored in vector <vector <long long>>. 
    //*If these 2 are the only info I need, I can just use a pair. 
    deque <pair <vector <vector <vector <long long>>>, vector <vector <long long>>>> q;
    q.push_back({{}, coords});
    pair <vector <vector <vector <long long>>>, vector <vector <long long>>> curr;

    //*The all permutaions uses a bunch of combinations. 
    vector <vector <vector <vector <long long>>>> all;
    while (!q.empty()){
        curr = q[0];
        q.pop_front();
        if (curr.second.size() == 0){
            all.push_back(curr.first);
        }
        else{
            for (long long i=0;i<curr.second.size();i++){
                for (long long j=i+1;j<curr.second.size();j++){
                    //!Same pairs could come in different order but reduces number signinficantly. 
                    auto next_first = curr.first;
                    auto next_second = curr.second;
                    //*Cannot erase consecutively but rather have to copy it in without touching the indexes. 
                    next_first.push_back({curr.second[i], curr.second[j]});
                    next_second.clear();

                    for (long long k=0;k<curr.second.size();k++){
                        if (k!=i && k!=j){
                            next_second.push_back(curr.second[k]);
                        }
                    }

                    q.push_back({next_first, next_second});

                

                }
            }
        }
    }

    //!Honestly, this problem is quite the boring one... let me try skipping it...
    for (auto pattern:all){
        for (auto one_pair:pattern){
            for (auto one_point:one_pair){
                /*
                for (auto one_coord:one_point){

                }
                */
                //!Instead of jumping to the next point, I should just start going right withou jumping. 
                for (auto check_point:coords){
                    if (check_point[1]==one)
                }
            }
        }
    }


}