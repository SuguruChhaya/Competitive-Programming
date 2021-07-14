#include <bits/stdc++.h>

using namespace std;

long long result =0;

vector <bool> column;
vector <bool> diag1;
vector <bool> diag2;
vector <vector <long long>> arr;

void recursive(long long row){
    if (row==8){
        result++;
    }
    else{
        for (long long col=0;col<8;col++){
            if (column[col] || diag1[col+row] || diag2[col-row+8-1] || arr[row][col]=='*'){

            }
            else{
                column[col] = diag1[col+row] = diag2[col-row+8-1] = 1;
                recursive(row+1);
                column[col] = diag1[col+row] = diag2[col-row+8-1] = 0;

            }
        }
    }
}

int main(){
    //*I see. The previous recursive approach had somewhat of backtracking involved. 
    //n is the number of rows, columns, as well as the number of queens. 

    //*Measure the rows and diagnonals separately. 
    //*Even if one works at one point, it may not end up working later on. 
    //*Thats why we could either use continue or else. 


    //*Additional challenge of spaces being reserved. 
    //*Doesn't change my vector relationship though. 
    
    
    

    for (long long i=0;i<8;i++){
        string temp;
        cin >> temp;
        vector <long long> temp_vector;
        for (long long j=0;j<8;j++){
            temp_vector.push_back(temp[j]);
        }
        arr.push_back(temp_vector);

        //*Create the helpful vectors too. 
        column.push_back(0);

    }

    for (long long numDiagonals=0;numDiagonals<(2*8-1);numDiagonals++){
        diag1.push_back(0);
        diag2.push_back(0);
    }

    recursive(0);
    cout << result << endl;
}