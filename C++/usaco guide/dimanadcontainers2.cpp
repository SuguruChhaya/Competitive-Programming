#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    stack <long long> s;
    //*Double ended queue. 
    queue <long long> q;
    deque <long long>d;

    vector <long long> instructions;
    vector <vector <long long>> output;
    //*Could store the index of all 0s.
    vector <long long> zero_index = {-1};
    for (long long i=0;i<n;i++){
        long long a;
        cin >> a;
        instructions.push_back(a);
        if (a==0){
            zero_index.push_back(i);
        }
        output.push_back({});
    }

    //?How should I prepare for output? 
    //!Definitely easier if I create same output.
    //*I can just compare with instructions to know whether I am adding or removing. 
    //*Stack: 0, Queue: 1, Front: 2, Back:3
    
    for (long long i=0;i<zero_index.size()-1;i++){
        //*Loop from the current to the next. 
        //*Honestly, index 0 must be added because it is the start. 
        vector <vector <long long>> sorted;
        for (long long index =zero_index[i]+1;index<zero_index[i+1];index++){
            //*To pick the max 3, the easiest is to add to vector and sort. 
            sorted.push_back({instructions[index], index});
        }
        sort(sorted.begin(), sorted.end());
        
        //*Now pick the largest 3 elements. 
        if (sorted.size()==1){
            //!Might as well skip this one cuz so much implementation based. 
            output[zero_index[i]+1].push_back(1);
            output[zero_index[i]+1].push_back();
            //*Just add it to the stack at that point. 
            output[sorted[0][1]].push_back(0);
        }
        else if (sorted.size()==2){
            //*Just add the first one to the stack and the second one to queue. 
            output[sorted[0][1]].push_back(0);
            output[sorted[1][1]].push_back(1);
        }
        else{
            //*Size is 3 or larger. 
            output[sorted[0][1]].push_back(0);
            output[sorted[1][1]].push_back(1);
            output[sorted[2][1]].push_back(2);
            //*Always push back to front. 
            
        }
        //*Push back all the other ones to back. 
        for (long long j=4;j<sorted.size();j++){
            output[sorted[sorted.size()-j][1]].push_back(3);
        }

        //*At the end, I should just check based on the length. 
        


    }

    //*Now loop through the zero_index array and check what happens until that point. 



    
}