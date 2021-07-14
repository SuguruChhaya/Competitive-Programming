#include <bits/stdc++.h>

using namespace std;

int main(){
    //*The tricky part is that there are 2 single kayaks. 
    //*All I can think of is to brute force the 2 people on single kayaks 

    long long n;
    cin >>n;
    vector <long long> arr;
    for (long long i=0;i<2*n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    long long result = 99999999999999999;
    vector <long long> temp;
    for (long long p1=0;p1<2*n;p1++){
        for (long long p2=p1+1;p2<2*n;p2++){
            //*Chose the 2 people who are going on single kayaks. 
            //*Start actually calculating starting from index 1. 
            long long currTotal=0;
            //!What if we choose to exclude the first element? 
            //*Prev index will still remain as 0. 
            //*That is why it is better to use a vector to store all previous elements. 
            //!I think https://programmersought.com/article/28727118593/
            //*was generally making the loop 1 indexed. 
            //*The i loop was <m because the j loop must be larger so it could be <m instead of <=m
            //!Uses x for the current index but if I use vector I could just use .size(). 
            for (long long i=0;i<2*n;i++){
                //*If i is on p1 or p2 just ignore. 
                if (i==p1 || i ==p2){}
                else{
                    temp.push_back(arr[i]);
                    if (temp.size() % 2==0){
                        currTotal += abs(temp[temp.size()-1]-temp[temp.size()-2]);
                    }
                    
                }
            }

            result = min(result, currTotal);
        }
    }
    cout << result << "\n";
}