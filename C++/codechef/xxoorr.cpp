#include <bits/stdc++.h>

using namespace std;


vector <long long> decToBinary(long long n){
    vector <long long> result;

    while (n > 0){
        result.push_back(n%2);
        n /= 2;
    }

    return result;
}
/*
int main(){

    //?Why is it a WA??

    long long t;
    //!I cannot just randomly choose values for p and index...
    //*We wanna cover a lot at once. 
    //!I don't think order really matters here. 
    //*We don't have to pick a contiguous segment. 
    //*We can only xor it by a power of 2. 1, 10, 100 etc. 
    //!Really the number of distinct 1 digit locations is the answer. 
    //*But there is the issue of K as well. 
    //*Keep a frequency array so I can deal with K later. 
    //*Convert to binary then iterate from the left and every time I hit a 1, update the frequnecy array. 
    //*Maybe there is a better way since 10^10 is really concerning. 

    vector <long long> frequency;
    //*Returned in reverse order. 

    
    cin >> t;

    
    for (long long i=0;i<t;i++){
        long long n, k;
        cin >> n >> k;

        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;

            //*Convert to binary and iterate. 
            //*I want the function to return a string instead of a number...

            auto v = decToBinary(temp);
            
            for (long long a=0;a<v.size();a++){
                //*Check whether that index exists. 
                //!Also make sure there is a 1. 
                if (v[a]==1){
                    if (frequency.size()>a){
                        //*Must be smaller since 0 indexing. 
                        frequency[a]++;
                    }
                    else{
                        frequency.push_back(1);
                    }
                }
            }
        }
        long long result = 0;
        for (long long j=0;j<frequency.size();j++){
            //*Check how many times I have to do it for each. 
            //*Ceil the value. 
            //!I have no idea about the WA...
            result+= ceil(frequency[j] / (k * 1.0));
        }

        cout << result << "\n";
    }
    //!I see how bitwise XORs could give unexpected results...
    //*Previous 0s will remain as 0s and 1s will remain as 1s tho...
    
}
*/

int main(){
    auto v = decToBinary(6);
    cout << v[0];
}