#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    long long n, m;
    cin >> m >> n;   
    //!Minestro can consume a single paint cartridge with his gun to add paint of the color of the cartridge to a contiguous sequence of adjacent cells in a single row.
    //*I guess I have to consider this and use 2 pointer. 
    vector <vector <char>> arr;
    vector <char> temp_vector;
    string temp_string;
    //*Just store a vector of how many of each I need.
    //*Order is red, yellow, blue. 
    map<char, vector <int>> hashmap = {
        {'.', {0, 0, 0}},
        {'R', {1, 0, 0}},
        {'U', {0, 0, 1}},
        {'Y', {0, 1, 0}},
        {'O', {1, 1, 0}},
        {'G', {0, 1, 1}},
        {'P', {1, 0, 1}},
        {'B', {1, 1, 1}}
    };

    for (long long i=0;i<n;i++){
        temp_vector = {};
        cin >> temp_string;
        for (long long j=0;j<m;j++){
            temp_vector.push_back(temp_string[j]);
        }
        arr.push_back(temp_vector);
    }
    //char prev;
    vector <long long> result = {0, 0,0};
    for (long long row=0;row<n;row++){
        //!Only for contiguous row so reset at every row. 
        //prev = arr[row][0];
        for (long long col=0;col<m;col++){
            //*How will I implement 2 pointer? 
            //*Segmentation fault cuz it doesn't exist huh? 
            //!Way more complicated than that. 
            //*Could be different color but they could both contain red. 
            //!just check whether the previous contained or not. 

            if (col==0){
                //*Don't add anything if the col is 0. 
                //*Once I finish processing then I willl add. 
            }
            else{
                if (hashmap[arr[row][col-1]][0]==1 && hashmap[arr[row][col]][0]==1){
                    //*Both red so don't do anything. 
                }
                //*If only the previous contained red then boom. 
                else if (hashmap[arr[row][col-1]][0]==1){
                    result[0]++;
                }
                //*Nothing to do if only the current one contains a red. 
                //*We will process the prev later. 

                if (hashmap[arr[row][col-1]][1]==1 && hashmap[arr[row][col]][1]==1){

                }
                else if (hashmap[arr[row][col-1]][1]==1){
                    result[1]++;
                }

                if (hashmap[arr[row][col-1]][2]==1 && hashmap[arr[row][col]][2]==1){

                }
                else if (hashmap[arr[row][col-1]][2]==1){
                    result[2]++;
                }
            }

            //*Have to process the last element too. Can just treat this one as individual. 
        }
        //*At the end of the row, add whatever is left over. 
        result[0] += hashmap[arr[row][m-1]][0];
        result[1] += hashmap[arr[row][m-1]][1];
        result[2] += hashmap[arr[row][m-1]][2];
    }

    cout << result[0] << " "<<result[1] << " " << result[2] << "\n";
}