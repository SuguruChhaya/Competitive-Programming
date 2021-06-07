#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int numTests;
    cin >> numTests;

    long long n, k;
    vector <char> arr;
    string s;
    long long location;
    long long distance;
    for (int i=0;i<numTests;i++){
        cin >> n >> k;
        cin >> s;
        arr = {};
        distance = 0;
        for (long long j=0;j<n;j++){
            arr.push_back(s[j]);
            //*Store the current distance. 
            if (j!=0){
                if (arr[j] != arr[j-1]){
                    //*Opposite charges so distance of 1. 
                    distance++;
                }
                else{
                    distance += 2;
                }
            }
        }
        for (long long j=0;j<k;j++){
            cin >> location;
            //*0 index. 
            if (arr[location-1] == '0'){
                arr[location-1] = '1';
                //*Compare with neighbors. Start and edge are special cases I need to consider.
                if (location-1 !=0){
                    //*There is an element to the left. 
                    if (arr[location-2] == '0'){
                        distance--;
                        //*Subtract the 2 distance that existed and add 1. 
                    }
                    else{
                        //*1 distance increase. 
                        distance++;
                    }
                }
                if (location-1!=arr.size()-1){
                    //*Has something to the right. 
                    if (arr[location]=='0'){
                        distance--;
                    }
                    else{
                        distance++;
                    }
                } 
            }
            else{
                //*Used to be 1
                arr[location-1] = '0';
                if (location-1!=0){
                    if (arr[location-2]=='0'){
                        distance++;
                    }
                    else{
                        distance--;
                    }
                }
            
                if (location-1!=arr.size()-1){
                    if (arr[location]=='0'){
                        distance++;
                    }
                    else{
                        distance--;
                    }
                }
            }
            cout << distance << "\n";
        }   
        
    }
}