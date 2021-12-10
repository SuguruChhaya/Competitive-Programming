#include <bits/stdc++.h>
using namespace std;
/*
Think of a tree
There can only be 3^9 possible boards but we can go back the tree and stuff so that becomes nasty. 

Store the type and the int. Tuple will work. 
Create the graph carrara was talking about

Set the visited of initial bessie position to true. 
Generate the stuff that comes next. 
can use queue
*/
long long n;
//*Adjacency thingy.
vector <vector <long long>> adj = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
//vector <vector<set<vector<vector<char>>>>> visited;
vector<vector<bool>> visited;
set<vector<vector<char>>> ans;
vector <vector <vector <char>>> arr;

bool has_won(vector<vector<char>>curr){
    vector<vector<long long>> cells (3, vector<long long>(3, 0));
    for (long long i=0;i<3;i++){
        for (long long j=0;j<3;j++){
            if (curr[i][j]=='M'){
                cells[i][j] = 1;
            }
            if (curr[i][j]=='O'){
                cells[i][j] = 2;
            }
        }
    }
    for (int r=0; r<3; r++) {
    if (cells[r][0] == 1 && cells[r][1] == 2 && cells[r][2] == 2) return true;
    if (cells[r][0] == 2 && cells[r][1] == 2 && cells[r][2] == 1) return true;
    }
    for (int c=0; c<3; c++) {
    if (cells[0][c] == 1 && cells[1][c] == 2 && cells[2][c] == 2) return true;
    if (cells[0][c] == 2 && cells[1][c] == 2 && cells[2][c] == 1) return true;
    }
    if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2) return true;
    if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1) return true;
    if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2) return true;
    if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1) return true;
    return false;
}

void dfs(long long row, long long col, vector<vector<char>>curr){
    //*Already says that border cells contain haybales. 
    cout << row << " " << col << endl;
    if (has_won(curr)){
        /*
        for (long long i=0;i<3;i++){
            for (long long j=0;j<3;j++){
                cout << curr[i][j];
            }
            cout << endl;
        }
        cout << endl;
        */
        ans.insert(curr);
        
    }
    //cout << row << " " << col << endl; 
    //?Can't we check first??

    //!Stop as soon as we hit winning. 
    //?Couldn't I reset the visited arr every time I hit?
    else if (!visited[row][col]){
        visited[row][col] = 1;
        auto next = curr;
        if((arr[row][col][0]=='M' || arr[row][col][0]=='O') && next[arr[row][col][1]-'1'][arr[row][col][2]-'1']=='.'){
            //!But I don't think that 
            next[arr[row][col][1]-'1'][arr[row][col][2]-'1'] = arr[row][col][0];
            //!Keeps resetting the values when it hits it. 
            //*So have to make it so it resets for first time but not other times. 

            visited = {};
            visited.resize(n, vector<bool>(n, 0));

        }
        if (arr[row][col][0]!='#'){
            for (auto e:adj){
                dfs(row+e[0], col+e[1], next);
            }
        }

    }
}
int main(){

    cin >> n;
    //visited.resize(n, vector <set<vector<vector<char>>>>(n));
    visited.resize(n, vector<bool>(n));
    arr.resize(n, vector <vector <char>>(n, vector <char>(3)));
    long long row, col;
    //set <char> ok = {'B', 'O', 'M'};
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j][0] >> arr[i][j][1] >> arr[i][j][2];
            if (arr[i][j][0]=='B'){
                row = i;
                col = j;
            }
        }
    }

    //vector <vector <bool>> visited(n, vector <bool>(n, 0));
    /*
    //*Start a process from all of them?
    for (auto p:q){
        visited.clear();
        visited.resize(n, vector<bool>(n, 0));
        
    }
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        //*Have to check whether current is valid. 
        if (!visited[curr[0]][curr[1]]&&arr[curr[0]][curr[1]]==)
    }
    */
    vector<vector<char>> start(3, vector<char>(3, '.'));
    dfs(row, col, start);
    cout << ans.size() << endl;
    /*
    for (auto e:ans){
        for (long long i=0;i<3;i++){
            for (long long j=0;j<3;j++){
                cout <<e[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    
}