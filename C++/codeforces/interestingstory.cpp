#include <bits/stdc++.h>
using namespace std;

double interesting_or_not(vector <long long> arr, long long index){
    long long without_target = 0;
    for (long long i=0;i<arr.size();i++){
        if (i!=index){
            without_target+=arr[i];
        }
    }

    if (arr[index] > without_target){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <vector <long long>> arr;
        //*The first vector contains all the counts for the words. The inner vector contains counts for individual letters. 
        //*I think I should also keep a total record for the number of each element. 
        vector <long long> total_char = {0,0,0,0,0};
        for (long long j=0;j<n;j++){
            vector <long long> frequency = {0, 0, 0, 0, 0};
            string s;
            cin >> s;
            //?Is it guaranteed that picking the character occuring the most will give me the best result??
            //!I think the approach is to first include all and then try removing words that prevent a majority character from appearing. 
            //*I really should try to make all the characters a majority element. 
            for (auto c:s){
                frequency[c-'a']++;
                total_char[c-'a']++;
            }
            arr.push_back(frequency);
        }
        long long result;
        for (long long i=0;i<5;i++){
            //*Trying to make each element a majority element. 
            //*First calculate the initial percentage. 
            while (!interesting_or_not(total_char, i)){
                
            }
        }
    }
}