#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

//*First implement the one from top to bottom. 

int test1(int n, int m, vector <vector <char>> arr){
    int current_size = min(n, m);
    bool found = false; 
    vector <vector <int>> queue;
    vector <int> curr;
    vector <int> bottom_right;
    vector <int> curr_coord;
    vector <int> up;
    vector <int> down;
    vector <int> left;
    vector <int> right;
    bool valid;
    int curr_row;
    int curr_col;
    while (current_size >= 1 && found == false){
        //*For the 3rd argument:
        //*0: just started off. 
        //*1: up
        //*2: down
        //*3: left
        //*4: right
        curr = {1, 1, 0};
        queue.push_back(curr);
        set <vector <int>> visited;
        while (queue.size() > 0){
            curr = queue[0];
            curr_coord = {curr[0], curr[1]};
            queue.erase(queue.begin());
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            valid = true;
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited.count(curr_coord) == 0
            ){
                if (curr[2] == 0){
                    for (int row=curr[0]; row < curr[0]+current_size; row++){
                        if (valid==false){
                            break;
                        }
                        for (int col=curr[1]; col < curr[1]+current_size; col++){
                            if (valid==false){
                                break;
                            }
                            if (arr[row-1][col-1] == 'X'){
                                valid = false;
                                break;
                            }
                        }
                    }
                }

                else if (curr[2] == 1 || curr[2] == 2){
                    if (curr[2]==1){
                        curr_row = curr[0];
                    }
                    else if (curr[2]==2){
                        curr_row = curr[0] + current_size -1;
                    }
                    for (int col=curr[1]; col<curr[1]+current_size;col++){
                        if (arr[curr_row-1][col-1]=='X'){
                            valid = false;
                            break;
                        }
                    }
            
                }

                else if (curr[2]==3 || curr[2]==4){
                    if (curr[2]==3){
                        curr_col = curr[1];
                    }
                    else if (curr[2]==4){
                        curr_col = curr[1]+current_size-1;
                    }
                    for (int row=curr[0]; row<curr[0]+current_size;row++){
                        if (arr[row-1][curr_col-1] == 'X'){
                            valid=false;
                            break;
                        }
                    }
                }

                if (valid==true){
                    visited.insert(curr_coord);
                    if (bottom_right[0] == n && bottom_right[1] == m){
                        found = true;
                        break;
                    }

                    up = {curr[0]-1, curr[1], 1};
                    down = {curr[0]+1, curr[1], 2};
                    left = {curr[0], curr[1]-1, 3};
                    right = {curr[0], curr[1]+1, 4};

                    queue.push_back(up);
                    queue.push_back(down);
                    queue.push_back(left);
                    queue.push_back(right);
                }
            
            }}

            if (found==false){
                current_size--;
                
            
        }


    }
    //!Accepted for first 2 cases but not the 3rd?
    if (current_size < 1){
        return 0;
    }
    else{
        return current_size;
    }


}




int test2(int n, int m, vector <vector <char>> arr){
    int low = 1;
    int high = min(n, m);
    int last_successful = 0;
    long current_size; //!Read some documentation and apparantly I should store in long. -> Sadly, not the reason. 
    vector <int> up;
    vector <int> down;
    vector <int> left;
    vector <int> right;
    vector <vector <int>> queue;
    vector <int> curr;
    vector <int> bottom_right;
    vector <int> curr_coord;
    bool chosen;
    bool valid;
    int curr_row;
    int curr_col;

    //!I have no idea why test case 5 is failing. 
    while (low <= high){
        chosen = false;
        current_size = floor((low+high) / 2); 
        curr = {1, 1, 0};
        queue = {};
        //!Is it possible that I am not clearing the queue when I finish?
        queue.push_back(curr);
        set <vector <int>> visited;
        while (queue.size() > 0){
            curr = queue[0];
            curr_coord = {curr[0], curr[1]};
            queue.erase(queue.begin());
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            valid = true;
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited.count(curr_coord) == 0
            ){
                curr_coord = {curr[0], curr[1]};
                visited.insert(curr_coord);

                if (curr[2] == 0){
                    for (int row=curr[0]; row < curr[0]+current_size; row++){
                        if (valid==false){
                            break;
                        }
                        for (int col=curr[1]; col < curr[1]+current_size; col++){
                            if (valid==false){
                                break;
                            }
                            if (arr[row-1][col-1] == 'X'){
                                valid = false;
                                break;
                            }
                        }
                    }
                }

                else if (curr[2] == 1 || curr[2] == 2){
                    if (curr[2]==1){
                        curr_row = curr[0];
                    }
                    else if (curr[2]==2){
                        curr_row = curr[0] + current_size -1;
                    }
                    for (int col=curr[1]; col<curr[1]+current_size;col++){
                        if (arr[curr_row-1][col-1]=='X'){
                            valid = false;
                            break;
                        }
                    }
            
                }

                else if (curr[2]==3 || curr[2]==4){
                    if (curr[2]==3){
                        curr_col = curr[1];
                    }
                    else if (curr[2]==4){
                        curr_col = curr[1]+current_size-1;
                    }
                    for (int row=curr[0]; row<curr[0]+current_size;row++){
                        if (arr[row-1][curr_col-1] == 'X'){
                            valid=false;
                            break;
                        }
                    }
                }

                if (valid == true){
                    if (n==bottom_right[0] && m==bottom_right[1]){
                        //!Not an issue with the max, min thing
                        last_successful = current_size;
                        chosen = true;
                        low = current_size + 1;
                        break;
                    }

                    up = {curr[0]-1, curr[1], 1};
                    down = {curr[0]+1, curr[1], 2};
                    left = {curr[0], curr[1]-1, 3};
                    right = {curr[0], curr[1]+1, 4};

                    queue.push_back(up);
                    queue.push_back(down);
                    queue.push_back(left);
                    queue.push_back(right);
                }



            }

        }

        if (chosen == false){
            high = current_size -1;
        }
    }

    //!Now some another crazy bug at case #4?
    return last_successful;

}

//!Even using C++, I will need binary search to pass this one huh?

//!Now I am gonna reuse the queue and do with binary search. 
//*This is getting real tedious now. 

int test3(int n, int m, vector <vector <char>> arr){
    int low = 1;
    int high = min(n, m);
    int last_successful = 0;
    int current_size; //!Read some documentation and apparantly I should store in long. -> Sadly, not the reason. 
    vector <int> up;
    vector <int> down;
    vector <int> left;
    vector <int> right;
    vector <vector <int>> queue;
    vector <int> curr;
    vector <int> bottom_right;
    vector <int> curr_coord;
    bool chosen;
    bool valid;
    int curr_row;
    int curr_col;

    //!I have no idea why test case 5 is failing. 
    while (low <= high){
        chosen = false;
        current_size = floor((low+high) / 2); 
        curr = {1, 1, 0};
        queue = {};
        //!Is it possible that I am not clearing the queue when I finish?
        queue.push_back(curr);
        set <vector <int>> visited;
        while (queue.size() > 0){
            curr = queue[0];
            curr_coord = {curr[0], curr[1]};
            queue.erase(queue.begin());
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            valid = true;
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited.count(curr_coord) == 0
            ){
                //curr_coord = {curr[0], curr[1]};
                visited.insert(curr_coord);

                if (curr[2] == 0){
                    for (int row=curr[0]; row < curr[0]+current_size; row++){
                        if (valid==false){
                            break;
                        }
                        for (int col=curr[1]; col < curr[1]+current_size; col++){
                            if (valid==false){
                                break;
                            }
                            if (arr[row-1][col-1] == 'X'){
                                valid = false;
                                break;
                            }
                        }
                    }
                }

                else if (curr[2] == 1 || curr[2] == 2){
                    if (curr[2]==1){
                        curr_row = curr[0];
                    }
                    else if (curr[2]==2){
                        curr_row = curr[0] + current_size -1;
                    }
                    for (int col=curr[1]; col<curr[1]+current_size;col++){
                        if (arr[curr_row-1][col-1]=='X'){
                            valid = false;
                            break;
                        }
                    }
            
                }

                else if (curr[2]==3 || curr[2]==4){
                    if (curr[2]==3){
                        curr_col = curr[1];
                    }
                    else if (curr[2]==4){
                        curr_col = curr[1]+current_size-1;
                    }
                    for (int row=curr[0]; row<curr[0]+current_size;row++){
                        if (arr[row-1][curr_col-1] == 'X'){
                            valid=false;
                            break;
                        }
                    }
                }

                if (valid == true){
                    if (n==bottom_right[0] && m==bottom_right[1]){
                        //!Not an issue with the max, min thing
                        last_successful = current_size;
                        chosen = true;
                        low = current_size + 1;
                        break;
                    }

                    up = {curr[0]-1, curr[1], 1};
                    down = {curr[0]+1, curr[1], 2};
                    left = {curr[0], curr[1]-1, 3};
                    right = {curr[0], curr[1]+1, 4};

                    queue.push_back(up);
                    queue.push_back(down);
                    queue.push_back(left);
                    queue.push_back(right);
                }



            }

        }

        if (chosen == false){
            high = current_size -1;
        }
    }

    //!Now some another crazy bug at case #4?
    return last_successful;

}
/*
int test4(int n, int m, vector <vector <char>> arr){
    //*I get how a prefix sum array could be used in that case. 
    //!But how can it be specifically used?
    //*I see kind of genius. 
    //*So basically if I moving down I check the column prefix sum array whether there are changes. 
    //*But if moving up check the row prefix array. I think I just need to check the top left corners and observe change. 
    return 0;
}
*/

void showVectorChar(vector <vector <char>> arr){
    for (int i=0; i<arr.size();i++){
        for (int j=0; j<arr[1].size(); j++){
            cout << arr[i][j];
        }

        cout << "\n";
    }
}

void showVectorLongLong(vector <vector <long long>> arr){
    for (int i=0; i<arr.size();i++){
        for (int j=0; j<arr[1].size(); j++){
            //*For some reason it just doesn't print. 
            cout << arr[i][j];
        }

        cout << endl;
    }
}
vector <long long> curr;
vector <vector <char>> arr;
vector <vector <long long>> prefix_row; //*Depends on how I think of it but this is like the orginal. 
vector <vector <long long>> prefix_col;
long long curr_prefix_row = 0;
long long curr_prefix_col = 0;
string s;
vector <char> temp_char;
vector <long long> temp_row, temp_col;
long long n, m;
long long low, high;
long long last_successful = 0;
long long current_size;
vector <vector <long long>> queue;
//!Don't have to explicitly define for up, down, left, or right. 
//*Probably won't need curr_coord. 
bool chosen, valid;
long long curr_row, curr_col;
auto visited=arr;
vector <long long> bottom_right;
long long mmax;
long long test4(){
    //*Said to binary search so do that the first time. 
    low = 1;
    high = min(n, m);
    last_successful = 0;
    
    while (low <= high){
        chosen = false;
        current_size = floor((low+high) / 2);
        curr = {1, 1, 0};
        queue = {};
        queue.push_back(curr);
        //!Not the problem of whether queue or not...
        visited = arr;
        //*I might have to implement where
        while (queue.size() > 0){
            curr = queue[0]; //!Curr value seems to be changing even before I assign anything. 
            queue.erase(queue.begin());
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            valid = true;
            //*Don't need a couple of checks but OK. 
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited[curr[0]-1][curr[1]-1] == 'O'
            ){
                //!I have no idea why bevans just doesn't TLE but mine does. 
                visited[curr[0]-1][curr[1]-1]='X';
                /*
                //!Why am I not even hitting this point???
                if (curr[0]==2 && curr[1]==1){
                    cout << "";
                }
                */
                
                //*For the first one, check the bottom right for both the prefix_row and prefix_col. 
                if (curr[2]==0){
                    //*If all conditions are met then do nothing. Otherwise turn into false. 
                    //*0 index. 
                    //!I need to check for both row and col. 
                    //*OK so how am I supposed to check the first one?
                    //*I guess I will try checking all the boards. 
                    
                    //!OK I don't need to look through everything. Just need to check the borders. 
                    /*
                    for (int row=curr[0]; row < curr[0]+current_size; row++){
                        if (valid==false){
                            break;
                        }
                        for (int col=curr[1]; col < curr[1]+current_size; col++){
                            if (valid==false){
                                break;
                            }
                            if (arr[row-1][col-1] == 'X'){
                                valid = false;
                                break;
                            }
                        }
                    }
                    */
                    
                    for (long long row=1;row<=current_size;row++){
                        if (prefix_row[row-1][bottom_right[1]-1]!=0){
                            valid = false;
                            break;
                        }
                    }
                    for (long long col=1;col<current_size;col++){
                        if (prefix_col[bottom_right[0]-1][col-1]!=0){
                            valid = false;
                            break;
                        }
                    }
                    
                    
                }
                else if (curr[2]==1 || curr[2]==2){
                    /*
                    if (prefix_col[curr[0]-1][curr[1]-1]==prefix_col[bottom_right[0]-1][bottom_right[1]-1]){

                    }//!I really should be using the row instead of col but HOW?
                    //*For the entering row, I have to check the leftmost and rightmost and see if they match. 
                    //!OK in detail:
                    //*
                    else{
                        valid = false; //!Why is the first invalid 3, 1? Shouldn't 2 1 come first?
                    }
                    */
                    
                    //!First of all, I forgot to separate the case for up and down. 
                    if (curr[2]==1){
                        //*Check the top row. So current index. 
                        if (curr[1]==1){
                            //*The left side is 0. 
                            if (prefix_row[curr[0]-1][bottom_right[1]-1]==0){

                            }
                            else{
                                valid = false;   
                            }
                        }
                        else{
                            if (prefix_row[curr[0]-1][bottom_right[1]-1]==prefix_row[curr[0]-1][curr[1]-2]){

                            }
                            else{
                                valid = false;
                            }
                        }

                    }

                    else if (curr[2]==2){
                        if (curr[1]==1){
                            if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==0){

                            }
                            else{
                                valid = false;
                            }
                        }
                        else{
                            if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==prefix_row[bottom_right[0]-1][curr[1]-2]){

                            }
                            else{
                                valid = false;
                            }
                        }
                    }


                //!My WHOLE DAMN PERCEPTION WAS WRONG!!
                //!Getting confused all over again. 

                //!OK so I think this is the REAL way. 
                //*Check whether the left most row-1 index matches with the rightmost index. This is because if leftmost is 1 then they will be same. 
                //*If -1 is 0 then set the value as 0. 
    
                } //!Now the reason is starting to get clear but what should I really check then??
                //?Why am I getting to 2, 2 on the left side? Why am I missing 2, 1?
                //!Because as soon as I visit from direction and I cannot go, it just gets marked and cannot go from correct direction too. 
            else if (curr[2]==3 || curr[2] == 4){
                /*
                if (prefix_row[curr[0]-1][curr[1]-1]==prefix_row[bottom_right[0]-1][bottom_right[1]-1]){

                }
                else{
                    valid = false; //!2, 2, is still on the invalid list and I have no idea why???
                }
                */
                
                if (curr[2]==3){
                    //*Moving left. 
                    if (curr[0]==1){
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==prefix_col[curr[0]-2][curr[1]-1]){

                        }
                        else{
                            valid=false;
                        }
                    }
                }
                else{
                    if (curr[0]==1){
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==prefix_col[curr[0]-2][bottom_right[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                    }
                }
            }
                if (valid==true){
                    if (n==bottom_right[0] && m==bottom_right[1]){
                        last_successful = current_size;
                        chosen = true;
                        low = current_size + 1;
                        break;
                    }
                    //!A more efficient way of debugging might be checking when the valid turns false since there must be some case that shouldn't be turned off. 
                    queue.push_back({curr[0]-1, curr[1], 1});
                    queue.push_back({curr[0]+1, curr[1], 2});
                    queue.push_back({curr[0], curr[1]-1, 3});
                    queue.push_back({curr[0], curr[1]+1, 4});
                }   
            }
        }
        if (chosen==false){
            high = current_size-1;
        }
    }
    return last_successful;
}


long long test6(){
    low = 1;
    high = min(n, m);
    while (low <= high){
        current_size = floor((low+high) / 2);
        queue = {{1, 1}};
        visited = arr;
        //*Why is visited[1][1] true??
        while (queue.size() > 0){
            curr = queue[0];
            queue.erase(queue.begin());
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            //*Just check for the best case right away. 


                if (1 <= curr[0] && 
                curr[0] <= n && 
                1 <= curr[1] && 
                curr[1] <= m && 
                1 <= curr[0] + current_size-1 && 
                curr[0]+current_size-1<=n && 
                1 <= curr[1]+current_size-1 && 
                curr[1]+current_size-1<=m &&
                visited[curr[0]-1][curr[1]-1] == 'O'
                ){
                    //*Brian is using whether the next anticipated item has been visited or not. 
                    visited[curr[0]-1][curr[1]-1] == 'X';
                    
                    //*What is brian doing with this Mmax variable?
                    //I see, he was trying to shrink it before hand since you already know that that size is not OK. 
                    //*If I initalize the prefix arrays 1 larger with the borders having 0s, we don't have to worry about the edge being 0. 
                    //*But let me do it my way since I want to. 
                    if (curr[0]==1 && curr[1]==1){
                        for (long long row=1;row<=current_size;row++){
                            if (prefix_row[row-1][bottom_right[1]-1]!=0){
                                valid = false;
                                break;
                            }
                        }
                        for (long long col=1;col<current_size;col++){
                            if (prefix_col[bottom_right[0]-1][col-1]!=0){
                                valid = false;
                                break;
                            }
                        }

                    }
                    else{
                    if (curr[1]==1){ 
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }

                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==0){
                            
                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==prefix_row[curr[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==prefix_row[bottom_right[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                    }

                    if (curr[0]==1){
                        //*Check if row==0 for columns. 
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==prefix_col[curr[0]-2][curr[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==prefix_col[curr[0]-2][bottom_right[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                    }

                    if (valid==true){
                        if (bottom_right[0]==n && bottom_right[1]==m){
                            last_successful = current_size; //!I think I need to check whether valid first. 
                            chosen = true;
                            low = current_size + 1;
                            break;
                            //*Chosen is just to know whether to continue or not. 
                        }
                        queue.push_back({curr[0]-1, curr[1], 1});
                        queue.push_back({curr[0]+1, curr[1], 2});
                        queue.push_back({curr[0], curr[1]-1, 3});
                        queue.push_back({curr[0], curr[1]+1, 4});
                    }
                }
                }
            }
        }
        if (chosen==false){
            high = current_size-1;

        }

    
    
    return last_successful;
}
/*
int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (long long i=0;i<n;i++){
        
        //*How am I gonna add this to the vector?
        cin >> s;
        //*Pretty sure m is the number of cols. 
        temp_row = {};
        temp_col = {};
        temp_char = {};
        //!The prefix table still isn't getting the values I want!!
        for (long long j=0;j<m;j++){
            //*Why is the char array size so weird? Why is it 8 instead of 4.
            temp_char.push_back(s[j]);
            if (s[j]=='X'){
                //*Use similar method for col so just get used to it from the start. 
                if (j==0){
                    temp_row.push_back(1);
                }
                else{
                    temp_row.push_back(temp_row[j-1]+1);
                }
                
                //*Check the prefix_col as well. 
                if (i==0){
                    temp_col.push_back(1);
                }
                else{
                    //*Retrieve data from previous row. 
                    temp_col.push_back(arr[i-1][j]+1);
                }
                
            }
            else{
                //*I have to check for first in this one as well., 
                if (j==0){
                    temp_row.push_back(0);
                }
                else{
                    temp_row.push_back(temp_row[j-1]);
                }
                //*The problem is on the line below. 
                //!The column example is special because coming in the first row is the first thing I have to check. 
                //temp_col.push_back(arr[i-1][j]);
            }
            //!Why is tempcol so bad??
            if (i==0){
                //*Even if i==0, there still can be an obstacle. 
                if (s[j]=='X'){
                    temp_col.push_back(1);
                }
                else{
                    temp_col.push_back(0);
                }
            }
            else{
                if (s[j]=='X'){
                    //*Since not first row, just add to the previous row. 
                    temp_col.push_back(prefix_col[i-1][j]+1);
                }
                else{
                    temp_col.push_back(prefix_col[i-1][j]);
                }
            }
        }
        prefix_row.push_back(temp_row);
        prefix_col.push_back(temp_col);
        arr.push_back(temp_char);

        //!I could just create a prefix array when traversing the row. Separate for col. 
    }
    //*Even for the showVectorChar only one line is showing why
    //showVectorChar(arr);
    //showVectorLongLong(prefix_row);
    //showVectorLongLong(prefix_col);
    //!The vector really isn't the issue. 
    //Call the actual algo. 
    cout << test6();
}
*/
bool test7(){
    queue = {{1, 1}};
    visited = arr;
    while (queue.size() > 0){
        curr = queue[0];
        queue.erase(queue.begin());
        bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};
            valid = true;
            //*Don't need a couple of checks but OK. 
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited[curr[0]-1][curr[1]-1] == 'O'
            ){
                visited[curr[0]-1][curr[1]-1]='X';
                if (curr[0]==1 && curr[1]==1){
                    for (long long row=1;row<=current_size;row++){
                        if (prefix_row[row-1][bottom_right[1]-1]!=0){
                            valid = false;
                            break;
                        }
                    }
                    for (long long col=1;col<current_size;col++){
                        if (prefix_col[bottom_right[0]-1][col-1]!=0){
                            valid = false;
                            break;
                        }
                    }
                }
                else{
                    //!The benefit for bevan's program is that I don't need to check all edges because I know which one I am going to. Kind of like me adding another element to queue. 
                    if (curr[1]==1){ 
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }

                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==0){
                            
                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==prefix_row[curr[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==prefix_row[bottom_right[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                    }

                    if (curr[0]==1){
                        //*Check if row==0 for columns. 
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==prefix_col[curr[0]-2][curr[1]-1]){

                        }
                        else{
                            //!Doing the same old 2, 2 is not OK thing. 
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==prefix_col[curr[0]-2][bottom_right[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                    }
                }
                if (valid==true){
                    if (bottom_right[0]==n && bottom_right[1]==m){
                        return true;
                        //*Chosen is just to know whether to continue or not. 
                    }
                    queue.push_back({curr[0]-1, curr[1], 1});
                    queue.push_back({curr[0]+1, curr[1], 2});
                    queue.push_back({curr[0], curr[1]-1, 3});
                    queue.push_back({curr[0], curr[1]+1, 4});
                }

    }
    
}return false;}

/*
int main(){
    //*Make it closer and closer to bevan's. 
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    high = min(n, m);
    for (long long i=0;i<n;i++){
        //!Probably adjusting the max is what makes the difference. 
        //*How am I gonna add this to the vector?
        cin >> s;
        //*Pretty sure m is the number of cols. 
        temp_row = {};
        temp_col = {};
        temp_char = {};
        //!The prefix table still isn't getting the values I want!!
        for (long long j=0;j<m;j++){
            //*Why is the char array size so weird? Why is it 8 instead of 4.
            temp_char.push_back(s[j]);
            if (s[j]=='X'){
                //*Use similar method for col so just get used to it from the start. 
                if (j==0){
                    temp_row.push_back(1);
                }
                else{
                    temp_row.push_back(temp_row[j-1]+1);
                }
                /*
                //*Check the prefix_col as well. 
                if (i==0){
                    temp_col.push_back(1);
                }
                else{
                    //*Retrieve data from previous row. 
                    temp_col.push_back(arr[i-1][j]+1);
                }
                

               //*Do the shrinking. 
               //!Can't copy exactly as bevan is doing because he is doing 1-indexed. 
               //!I really have no idea why it is i==m,  shouldn't 
               //?I think there is a way simpler way. 
               //!We cannot just naively take the minimum since it can be on row 1 but col 10000 but that doesn't mean 1000. 
                high = min(high, max(i, j));

            }
            else{
                //*I have to check for first in this one as well., 
                if (j==0){
                    temp_row.push_back(0);
                }
                else{
                    temp_row.push_back(temp_row[j-1]);
                }
                //*The problem is on the line below. 
                //!The column example is special because coming in the first row is the first thing I have to check. 
                //temp_col.push_back(arr[i-1][j]);


            }
            //!Why is tempcol so bad??
            if (i==0){
                //*Even if i==0, there still can be an obstacle. 
                if (s[j]=='X'){
                    temp_col.push_back(1);
                }
                else{
                    temp_col.push_back(0);
                }
            }
            else{
                if (s[j]=='X'){
                    //*Since not first row, just add to the previous row. 
                    temp_col.push_back(prefix_col[i-1][j]+1);
                }
                else{
                    temp_col.push_back(prefix_col[i-1][j]);
                }
            }
        }
        prefix_row.push_back(temp_row);
        prefix_col.push_back(temp_col);
        arr.push_back(temp_char);
    }
    //showVectorLongLong(prefix_col);
    //*Do the binary search here because hard to stuff it into 1 function. 
    low = 1;
    
    //!No idea why I still TLE...
    while (low <= high){
        current_size = floor((low+high) / 2);
        if (test7()){
            low = current_size+1;
        }
        else{
            high = current_size-1;
        }
    }
    cout << low-1;

}
*/



/*
bool found = false;
auto next_arr = queue;

long long test5(){
    //*Don't use BFS but reuse the queue. 
    queue.push_back({1, 1});
    current_size = min(n, m);
    while (current_size >= 1 && found==false){
        //*Since constant time, I don't really think direction matters that much. 
        next_arr = {};
        while (queue.size() > 0){
            curr = queue[0];
            queue.erase(queue.begin());
            valid = true;
            bottom_right = {curr[0]+current_size-1, curr[1]+current_size-1};      
            if (1 <= curr[0] && 
            curr[0] <= n && 
            1 <= curr[1] && 
            curr[1] <= m && 
            1 <= curr[0] + current_size-1 && 
            curr[0]+current_size-1<=n && 
            1 <= curr[1]+current_size-1 && 
            curr[1]+current_size-1<=m &&
            visited.count({curr[0], curr[1]}) == 0
            )
            //!Maybe it could be counting whether it is in the set that is taking up so much time!!{
                //*Only for {1, 1} we need to check everything.
                if (curr[0]==1 && curr[1]==1){
                    for (long long row=1;row<=current_size;row++){
                        if (prefix_row[row-1][bottom_right[1]-1]!=0){
                            valid = false;
                            break;
                        }
                    }
                    for (long long col=1;col<current_size;col++){
                        if (prefix_col[bottom_right[0]-1][col-1]!=0){
                            valid = false;
                            break;
                        }
                    } 
                }
                else{
                    if (curr[1]==1){ 
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }

                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==0){
                            
                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_row[curr[0]-1][bottom_right[1]-1]==prefix_row[curr[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_row[bottom_right[0]-1][bottom_right[1]-1]==prefix_row[bottom_right[0]-1][curr[1]-2]){

                        }
                        else{
                            valid = false;
                        }
                    }

                    if (curr[0]==1){
                        //*Check if row==0 for columns. 
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==0){

                        }
                        else{
                            valid = false;
                        }
                    }
                    else{
                        if (prefix_col[bottom_right[0]-1][curr[1]-1]==prefix_col[curr[0]-2][curr[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                        if (prefix_col[bottom_right[0]-1][bottom_right[1]-1]==prefix_col[curr[0]-2][bottom_right[1]-1]){

                        }
                        else{
                            valid = false;
                        }
                    }



                }
            }
            if (valid == true){
                visited.insert(curr);
                if (bottom_right[0]==n && bottom_right[1]==m){
                    found = true;
                    break;
                }
                queue.push_back({curr[0]-1, curr[1]});
                queue.push_back({curr[0]+1, curr[1]});
                queue.push_back({curr[0], curr[1]-1});
                queue.push_back({curr[0], curr[1]+1});
            }
            else{
                next_arr.push_back(curr);
            }
        }
        if (found==false){
            current_size--;
            queue = next_arr;
        }
    }
    if (current_size<1){
        return 0;
    }
    return current_size;
}
*/

vector <vector <char>> graph;
vector <vector <long long>> rspa;
vector <vector <long long>> cpsa;
bool bfs(long long size){
    queue = {{1, 1}};
    vector <vector <bool>> visited;
    //*Initialize visited. 
    vector <bool> temp;
    for (long long i=0;i<n+1;i++){
        temp = {};
        for (long long j=0;j<m+1;j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }

    visited[1][1] = true;
    while (queue.empty() == false){
        curr = queue[0]; //*I guess it is hard to print a bool to debug console. 
        queue.erase(queue.begin()); //!Only after one move it just terminated...
        //!What just went all the way to 3, 1 and just stopped??
        //!Were added to the queue but doesn't work somehow. 

        //!Now getting some weird WA why??
        if (curr[0]+size-1==n && curr[1]+size-1==m){
            return true;
        }
        //?Maybe some kind of typo...
        //*The checking method is the exact same. 
        if (curr[0]+size <= n && !visited[curr[0]+1][curr[1]] && rspa[curr[0]+size][curr[1]+size-1] - rspa[curr[0]+size][curr[1]-1]==0){
            queue.push_back({curr[0]+1, curr[1]});
            visited[curr[0]+1][curr[1]] = true;
        }
        if (curr[1]+size <= m && !visited[curr[0]][curr[1]+1] && cpsa[curr[0]+size-1][curr[1]+size] - cpsa[curr[0]-1][curr[1]+size]==0){
            queue.push_back({curr[0], curr[1]+1});
            visited[curr[0]][curr[1]+1] = true;
        }
        //!Would I ever maybe run out of grid?? No because curr[1]+size <=m has one space gap so checking whether I can move in there. 
        if (curr[0]-1>=1 && !visited[curr[0]-1][curr[1]] && rspa[curr[0]-1][curr[1]+size-1] - rspa[curr[0]-1][curr[1]-1]==0){
            queue.push_back({curr[0]-1, curr[1]});
            visited[curr[0]-1][curr[1]] = true;
        }
        if (curr[1]-1>=1 && !visited[curr[0]][curr[1]-1] && cpsa[curr[0]+size-1][curr[1]-1]-cpsa[curr[0]-1][curr[1]-1]==0){
            queue.push_back({curr[0], curr[1]-1});
            visited[curr[0]][curr[1]-1] = true;
        }
    }
    return false;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> m;

    long long mmax = min(n, m);
    vector <long long> temp;
    vector <char> temp_char_vector;
    //*OK initialize to random value. 
    for (long long i=0;i<n+1;i++){
        temp = {};
        temp_char_vector = {};
        for (long long j=0;j<m+1;j++){
            temp.push_back(0);
            temp_char_vector.push_back(' ');
        }
        graph.push_back(temp_char_vector);
        rspa.push_back(temp);
        cpsa.push_back(temp);

    }

    
    for (long long i=1;i<=n;i++){
        cin >> s;
        for (long long j=1;j<=m;j++){
            graph[i][j]=s[j-1];
            if (graph[i][j]=='X'){
                if (j==1 || i==m){
                    mmax = min(mmax, i-1);
                }
                else if (i==1 || j==n){
                    mmax = min(mmax, j-1);
                }
                else{
                    mmax = min(mmax, max(i-1, j-1));
                }
                //*rspa isn't initialized here. 
                rspa[i][j] = rspa[i][j-1]+1;
            }
            else{
                rspa[i][j] = rspa[i][j-1];
            }
        }
    }

    for (long long i=1;i<=m;i++){
        for (long long j=1;j<=n;j++){
            if (graph[j][i]=='X'){
                cpsa[j][i] = cpsa[j-1][i]+1;
            }
            else{
                cpsa[j][i] = cpsa[j-1][i];
            }
        }
    }

    low = 1;
    high = mmax;
    //!Doesn't recognize correct for size==3. 
    //*low=mid+1 must be the working condition. 
    while (low <= high){
        long long mid = (low+high) / 2;
        if (bfs(mid)){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    cout << low-1 << "\n";
}