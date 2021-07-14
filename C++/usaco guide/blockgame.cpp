#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    //*Basically I can generate all possible permutations and calculate the number of alphabets required for them. 
    //*Instead of manually typing all alphabets, isn't there something like chr or od in c++? 
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    vector <long long> original, curr, temp_occurences1, temp_occurences2;
    for (long long i=0;i<26;i++){
        original.push_back(0);
    }
    curr = original;

    long long n;
    cin >> n;
    
    //*Store the words in a pair or something. 
    vector <pair <string, string>> arr;
    string temp1, temp2;
    for (long long i=0;i<n;i++){
        cin >> temp1 >> temp2;
        //arr.push_back({temp1, temp2});
        temp_occurences1 = original;
        temp_occurences2 = original;

        for (long long j=0;j<temp1.size();j++){
            temp_occurences1[temp1[j]-97]++;
        }
        for (long long j=0;j<temp2.size();j++){
            temp_occurences2[temp2[j]-97]++;
        }
        //!Why do the other ones not increase??
        //*Loop through all then create the max. 
        for (long long j=0;j<curr.size();j++){
            //*Really the size is 26.
            //*Add the maximum for each. 

            curr[j] += max(temp_occurences1[j],temp_occurences2[j]);
        }
    }

    for (long long i=0;i<curr.size();i++){
        cout << curr[i] << "\n";
    }

    //*Create all the permutations. 
    //*Information I will need to store: the current strings (stored in vector)
    //*I don't really have to store index becuase based on length we can figure it out. 

    //!I think generating all permuations might TLE because 2^100 is too big. 
    //*There should be a way where we just have to look through the words once and figure it out. 
    //*take the max for the 2 numbers and keep going. 
    
}