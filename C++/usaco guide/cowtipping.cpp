#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <char>> arr;

bool all_correct(long long row){
    for (long long col = 0;col<n;col++){
        if (arr[row][col]=='1'){
            return false;
        }
    }
    return true;
}
void flip(long long row, long long col){

    for (long long flip_row=0;flip_row<=row;flip_row++){
        for (long long flip_col=0;flip_col<=col;flip_col++){
            if (arr[flip_row][flip_col]=='0'){
                arr[flip_row][flip_col]='1';
            }
            else{
                arr[flip_row][flip_col]='0';
            }
        }
    }
}
int main(){
    //*We wanna bring the cows closer to the left-top so that it is easy to tip them over. 
    //!We have to tip each row anyways, right??
    //*Tip from the bottom so I can move my way up. 
    //!Here, the scoop from the right approach might be helpful because we are starting from index 0 always but we don't know where to stop. 
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    
    cin >> n;
    

    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        vector <char> temp;
        for (long long j=0;j<n;j++){
            temp.push_back(s[j]);
        }
        arr.push_back(temp);
    }

    long long result = 0;
    for (long long row=n-1;row>=0;row--){
        while (!all_correct(row)){
            result++;
            long long col=n-1;
            while (col >= 0 && arr[row][col]=='0'){
                col--;
            }
            flip(row, col);
        }

        /*
        for (long long col=n-1;col>=0;col--){
            //*Check from the back whether there are missing or not. 
        }
        */
        //*Keep flipping until every thing is 0. 
        /*
        bool all_1 = false;
        while (all_1 == false){
            all_1 = true;
            long long col = n-1;
            while (col >= 0 && arr[row][col]==0){
                col--;
            }
            //*
            //*If we reach -1 then we are already correct. 
            //*Only if the loop is ran at least once, we keep going.
            //*We actually have to loop through all the rows upto that point. 

            for (long long flip_row=0;flip_row<=row;flip_row++){
                for (long long flip_col=0;flip_col<=col;flip_col++){
                    all_1 = false; //*Since we are flipping. 
                    if (arr[row][flip_col]==0){
                        arr[row][flip_col]=1;

                    }
                    else{
                        arr[row][flip_col]=0;
                    }
                }
            }
            for (long long flip_col=0;flip_col<=col;flip_col++){

                all_1 = false;
            }
        }
        */


    }
    cout << result << endl;
}