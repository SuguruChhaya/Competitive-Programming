#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <map>
using namespace std;


int showVector(vector <vector <vector <int>>> arr){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            for (int k=0;k<arr[i][j].size();k++){
                cout << arr[i][j][k];
            }
            cout << " ";
        }
        cout << endl;
    }
    return 1;
}

int hidenseek(int n, int m, int t, vector <int> start, vector <vector <int>> hiders, vector <vector <char>> arr){
    //*First generate all possible orders. 
    vector <vector <int>> curr = {start};
    vector <vector <vector <int>>> queue = {curr};
    vector <vector <vector <int>>> permutations;
    vector <vector <int>> temp;
    //!Store all the points I have added. 
    //vector <
    //!For some reason, number of permutations isn't increasing. 
    while (queue.size() > 0){
        curr = queue[0];
        queue.erase(queue.begin());

        //!If we have already chosen all, I don't need to do anymore stuff. 
        if (curr.size() == t+1){
            permutations.push_back(curr);
        }
        //*Need to make sure it is in range. 
        //!I see, because everything was registered based on array indices, I need to follow that.
        //!Actually, I don't have to check for range since everything is in range.  
        else{
            //*Iterate through all hiders and check whether they already exist. 
            for (int i=0; i<hiders.size();i++){
                //*Find function has some kind of error. 
                //if (find(curr.begin(), curr.end(), hiders[i]) == curr.end()){
                //!
                if (count(curr.begin(), curr.end(), hiders[i])==0){
                    //*Element doesn't exist. 
                    temp = curr;
                    temp.push_back(hiders[i]);
                    queue.push_back(temp);
                }
            }
        }
    }
    //!Segmentation fault is happening in the showing loop. 
    //showVector(permutations);

    //return 1;

    //*Loop through all the permutations. 
    //*Loop through every step
    //*Find the shortest path using BFS. 
    //*Probably store in a DP array for future use. 
    //!I have to map the starting point to ending point. Doesn't matter if it is in opposite order. 
    map <vector <vector <int>>, int> subtask;
    vector <vector <int>> queue2;
    vector <vector <int>> front;
    vector <vector <int>> reversed;
    vector <int> current;
    set <vector <int>> visited;
    //!Since BFS, just keep a set for each since even if I reach it later, it doesn't work.
    int curr_length;
    int result = 999999;
    for (int i=0; i<permutations.size();i++){
        //*size()-1 because we are checking j and j+1
        curr_length = 0;
        //!Don't know why the loop is running for so long. 
        for (int j=0; j<permutations[i].size()-1;j++){
            //*Before adding, check whether it exists in queue or not. 
            visited = {};
            front = {permutations[i][j+1], permutations[i][j]};
            reversed = {permutations[i][j], permutations[i][j+1]};

            if (subtask.count(front) == 1){
                curr_length += subtask[front];
            }
            else if (subtask.count(reversed) == 1){
                curr_length += subtask[reversed];
            }
            else{
                //!Current actually has to hold the number it took to get there as well. 
                //!Convenient that I can just build an array like that and don't need to make temp arrays for everything. 
                queue2 = {{permutations[i][j][0], permutations[i][j][1], 0}};
                while (queue2.size() > 0){
                    current = queue2[0];
                    queue2.erase(queue2.begin());
                    //!There cannot be a case where each permutation has length 1 or less since it includes the starting point. 
                    bool one = current[0] == permutations[i][j+1][0];
                    bool two = current[1]==permutations[i][j+1][1];
                    if (one && two){
                        curr_length += current[2];
                        subtask[{permutations[i][j], permutations[i][j+1]}] = current[2];
                        break;
                    }

                    //!If runs out of time, I can try marking already visited nodes but won't worry for the time-being. 
                    //*Just check for out of bounds and whether there is no wall. 
                    else if (
                        0 <= current[0] &&
                        current[0] < n &&
                        0 <= current[1] &&
                        current[1] < m && 
                        arr[current[0]][current[1]] != 'X' &&
                        visited.count(current) == 0
                    ){
                        visited.insert(current);
                        queue2.push_back({current[0]+1, current[1], current[2]+1});
                        queue2.push_back({current[0]-1, current[1], current[2]+1});
                        queue2.push_back({current[0], current[1]+1, current[2]+1});
                        queue2.push_back({current[0], current[1]-1, current[2]+1});
                    }
                    //cout << "stuck";
                }
            }
        }
        result = min(result, curr_length);
    }

    return result;

}


int main(){
    //*Naive BFS won't work because there are a lot of hiders so I have to do this separately. 
    //*If I know the end nodes and all the paths I have visited so far, I think I could do a double BFS. 
    //*First for all the paths I need to check so far and second for the closest path from that point to next. 

    //?Actually, I think I could generate all the permutations first then find the shortest distance for individual edges. 

    int t, n, m;
    cin >>  n >> m >> t;

    //*Store the starting position. Store seekers position in a hashset. 
    vector <vector <char>> arr;
    vector <char> temp;
    vector <int> start;
    vector <int> temp_hider;
    vector <vector <int>> hiders;
    string s;
    for (int i=0; i<n; i++){
        temp = {};
        cin >> s;
        for (int j = 0; j < m;j++){
            temp.push_back(s[j]);
            if (s[j] == 'G'){
                start = {i, j};
            }
            else if (s[j] == 'H'){
                temp_hider = {i, j};
                hiders.push_back(temp_hider);
            }
        }
        arr.push_back(temp);
    }

    cout << hidenseek(n, m, t, start, hiders, arr);
}   