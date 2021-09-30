#include <bits/stdc++.h>
using namespace std;

vector <long long> cow, stall;
vector <long long> occupied;
vector <vector <long long>> can_fit;
long long n;
long long result = 0;
void recursive(long long index){
    //*Dealing with the cow with the at the index. 
    if (index==n){
        result++;
        return;
    }
    
    for (auto i:can_fit[index]){
        if (cow[index] <= stall[i] && occupied[i]==0){
            occupied[i]=1;
            recursive(index+1);
            occupied[i]=0;
        }
    }
}


int main(){
    //*This might become a fun recursive problem. 
    cin >> n;
    

    for (long long i=0;i<n;i++){
        cow.push_back(0);
        cin >> cow[i];
        can_fit.push_back({});
        
    }
    for (long long i=0;i<n;i++){
        stall.push_back(0);
        cin >> stall[i];
        occupied.push_back(0);
    }
    //!I can think of couple of optimizations. 
    //*Make a predertimined map of the indexes that the cow[index] could stay in stall indexes 1,2,3 etc. 
    //*This way I only need to loop through the indexes in the vector. 
    //*Also I can prevent so many cases going nowhere, I could sort the cows based on the the number of places they could belong. 
    //*And start off by prioratizing the cows that have few places they can go. 
    //*So that more likely to end up in good spot. 

    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (cow[i]<=stall[j]){
                can_fit[i].push_back(j);
            }
        }
    }

    //!Recursive solution doesn't work. 
    //*Could use the smart way of using one array. 
    recursive(0);
    cout << result << endl;
}