#include <bits/stdc++.h>
using namespace std;

int main(){
    //*I cannot just start assigning greedily right??
    //!I think I can sort an array based on the beauty value and try them one by one. 
    //*If they cannot fit in there, move on to the next and so on. 
    //!I feel like this method is kinda like greedy and won't work all the time though...

    //*Must be alternating. 
    //!What a fucking ad-hoc problem this is. 
    long long n;
    cin >> n;
    vector <vector <long long>> beauty_arr;
    vector <vector <char>> cow_arr;
    
    for (long long i=0;i<n;i++){
        vector <char> temp_vector;
        for (long long j=0;j<n;j++){
            long long beauty;
            cin >> beauty;
            beauty_arr.push_back({beauty, i, j});
            temp_vector.push_back('.');
        }
        cow_arr.push_back(temp_vector);
    }

    sort(beauty_arr.begin(), beauty_arr.end(), greater<>());
    long long result = 0;
    //!I need to loop through all of beauty_arr thing. 
    for (long long i=0;i<beauty_arr.size();i++){
        //*First check whether row is larger than 0.
        //!This means that there could be stuff above. 
        //*But I still don't know whether left or right up.  
        //cout << beauty_arr[i][0] << " " << beauty_arr[i][1] << " " << beauty_arr[i][2] << endl;
        bool can_place = true;
        long long row = beauty_arr[i][1], col = beauty_arr[i][2];
        if (beauty_arr[i][1] > 0){
            if (beauty_arr[i][2] > 0){
                //*There is gonna be up left
                long long numcows = 0;
                
                if (cow_arr[row-1][col]=='C'){
                    numcows++;
                }
                if (cow_arr[row-1][col-1]=='C'){
                    numcows++;
                }
                if (cow_arr[row][col-1]=='C'){
                    numcows++;
                }

                if (numcows >= 2){
                    //*If it is already larger or equal to 2, we cannot place a cow there. 
                    can_place = false;
                }
                /*
                else{
                    cow_arr[row][col] = 'C';
                    result += beauty_arr[i][0];
                }*/
            }
            if (beauty_arr[i][2] < n-1){
                //*There is gonna be up right. 
                long long numcows = 0;
                //long long row = beauty_arr[i][1], col = beauty_arr[i][2];
                if (cow_arr[row-1][col]=='C'){
                    numcows++;
                }
                if (cow_arr[row-1][col+1]=='C'){
                    numcows++;
                }
                if (cow_arr[row][col+1]=='C'){
                    numcows++;
                }

                if (numcows >= 2){
                    can_place = false;
                }
                /*
                else{
                    //!I cannot just place just because it satisfies one condition. It must satisfy all conditions. 
                    cow_arr[row][col] = 'C';
                    result += beauty_arr[i][0];
                }
                */
            }
        }
        //*Check if there is going to be a down. 
        if (beauty_arr[i][1] != n - 1){
            if (beauty_arr[i][2] > 0){
                //*There is gonna be down left
                long long numcows = 0;
                //long long row = beauty_arr[i][1], col = beauty_arr[i][2];
                if (cow_arr[row+1][col]=='C'){
                    numcows++;
                }
                if (cow_arr[row+1][col-1]=='C'){
                    numcows++;
                }
                if (cow_arr[row][col-1]=='C'){
                    numcows++;
                }

                if (numcows >= 2){
                    //*If it is already larger or equal to 2, we cannot place a cow there. 
                    can_place = false;
                }
                /*
                else{
                    cow_arr[row][col] = 'C';
                    result += beauty_arr[i][0];
                }
                */
            }

            if (beauty_arr[i][2] < n-1){
                //*There is gonna be down right. 
                long long numcows = 0;
                //long long row = beauty_arr[i][1], col = beauty_arr[i][2];
                if (cow_arr[row+1][col]=='C'){
                    numcows++;
                }
                if (cow_arr[row+1][col+1]=='C'){
                    numcows++;
                }
                if (cow_arr[row][col+1]=='C'){
                    numcows++;
                }

                if (numcows >= 2){
                    can_place = false;
                }
                /*
                else{
                    cow_arr[row][col] = 'C';
                    result += beauty_arr[i][0];
                }
                */
            }
        }

        if (can_place==true){
            cow_arr[row][col] = 'C';
            result += beauty_arr[i][0];
        }


    }

    cout << result << endl;

    
}