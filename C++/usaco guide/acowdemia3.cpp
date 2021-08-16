#include <bits/stdc++.h>
using namespace std;

int main(){

    //!Based on official solution:
    //!The whole reason I was checking whether the pair exists in the set was because I thought the 2 might collide again. 
    //*If there are 3 or more cows, there must be one pair that is on opposite sides. This pair can only be made by that grass so I can confidently pair them up. 
    //*Now, if there are 2 cows, there could still be a chance of double pairing. But since that is the only pairing, it is that or nothing else. So I can just insert in set anyways and later hope there wasn't a duplicate. 

    



    long long n, m;
    cin >> n >> m;
    vector <vector <char>> arr;
    for (long long i=0;i<n;i++){
        vector <char> temp;
        string s;
        cin >> s;
        for (long long j=0;j<m;j++){
            temp.push_back(s[j]);
        }
        arr.push_back(temp);
    }
    set <vector <vector <long long>>> pairs;
    //*Set contains all the pairs, one pair contains 2 points, 1 point contains row and col. 

    //!For the sorting one. 
    //*When there are 0 or 
    //!There is no rule that I canot reuse the cows twice. However, if the pair already are friends, I have to pick a different pair. 
    //*Pairs should always be in sorted order (based on row then based on col.)
    //*Based on this, I need to store the number of adjacent cows in long long and all the coordinates in a 2D vector. 
    vector <pair <long long, vector <vector <long long>>>> grasses;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            if (arr[i][j]=='G'){
                //*Check if top row exists. 
                pair <long long, vector <vector <long long>>> grass;
                grass.first = 0;
                grass.second = {};
                if (i-1 >= 0 && arr[i-1][j]=='C'){
                    grass.first++;
                    grass.second.push_back({i-1, j});            
                }
                //*Check if left col exists. 
                if (j-1 >= 0 && arr[i][j-1]=='C'){
                    grass.first++;
                    grass.second.push_back({i, j-1});
                }
                //*Check if right col exists. 
                if (j+1 < m && arr[i][j+1]=='C'){
                    grass.first++;
                    grass.second.push_back({i, j+1});
                }
                //*Check if bottom row exists.
                if (i+1 < n && arr[i+1][j]=='C'){
                    grass.first++;
                    grass.second.push_back({i+1, j});
                }

                grasses.push_back(grass);
            }
        }
    }

    //*Now sort the array (will sorting work correctly for pairs??) -> YES, it does. 
    sort(grasses.begin(), grasses.end());

    //cout << grasses.size() << endl;
    for (auto grass:grasses){
        if (grass.first < 2){

        }
        //*Loop through all and check whether it already exists. 
        else{
            bool found = false;
            for (long long p1=0;p1<grass.second.size();p1++){
                for (long long p2=p1+1;p2<grass.second.size();p2++){
                    //*Always in sorted order. 
                    if (pairs.count({grass.second[p1], grass.second[p2]})==0){
                        //*If it doesn't yet exist.
                        pairs.insert({grass.second[p1], grass.second[p2]});
                        //*Wanna break from this entire loop really. 
                        found = true;
                        break;
                    }
                }
                if (found){
                    break;
                }
            }
        }
    }

    cout << pairs.size() << endl;
}