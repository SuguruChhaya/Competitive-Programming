#include <bits/stdc++.h>

using namespace std;

long long result =0;

vector <bool> column;
vector <bool> diag1;
vector <bool> diag2;
vector <vector <char>> arr;

bool evaluate(){
    //*First set up the diagonal arrays. 
    for (long long numDiagonals=0;numDiagonals<(2*8-1);numDiagonals++){
        diag1.push_back(0);
        diag2.push_back(0);
    }

    //*Now check for every row, col and see whether diagonals don't collide. 
    for (long long row=0;row<8;row++){
        for (long long col=0;col<8;col++){
            //*Check if the current is a queen ('X') or not. 
            if (arr[row][col]=='X'){
                if (diag1[col+row] || diag2[col-row+8-1]){
                    return false;
                }
                //!Hard to debug this shit...
                diag1[col+row] = diag2[col-row+8-1] = 1;
            }
        }
    }
    return true;
}

void recursive(long long row){
    if (row==8){
        //*Found solution so evaluate whether valid. 
        if(evaluate()){
            result++;
        }
    }
    else{
        for (long long col=0;col<8;col++){
            if (column[col] || arr[row][col]=='*'){

            }
            else{
                column[col]=1;
                arr[row][col]= 'X';
                recursive(row+1);
                column[col]=0;
                arr[row][col]='.';
            }
        }
    }
}

int main(){
    //*Another approach is to just generate all possible permutations first just based on row, col and availability. 
    //*Then check the permutation is valid on diagonal or not. 

    for (long long i=0;i<8;i++){
        string temp;
        cin >> temp;
        vector <char> temp_vector;
        for (long long j=0;j<8;j++){
            temp_vector.push_back(temp[j]);
        }
        arr.push_back(temp_vector);

        //*Create the helpful vectors too. 
        column.push_back(0);

    }

    //*Maybe I could use that weird recursion trick to reduce array memory? 
    for (long long i=0;i<8;i++){
        column.push_back(0);
    }

    recursive(0);
    cout << result << endl;
}