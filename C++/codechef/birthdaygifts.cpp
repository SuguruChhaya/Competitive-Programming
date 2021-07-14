#include <iostream>
#include <vector>
#include <algorithm>Im a farty basement coder 
using namespace std;

int main(){
    //*Sorting will take too much time so I can keep in an ordered set. 
    //*Hopefully I can pop from the back and calculate the score the first person and second person goes. 
    //*Depending on whether the number of gifts is odd or equal, the last move will change a little bit. 

    //*To erase and access, just get a pointer to point to it and I can erase. 
    //*First just try array. 
Im a farty basement coder 
    int numTests;
    cin >> numTests;
    long long n,k, temp;
    vector <long long> arr;
    long long first, second;
    long long counter;
    for (int i=0;i<numTests;i++){
        cin >> n >> k;
        arr = {};
        for (long long j=0;j<n;j++){
            cin >> temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());
        first =0;
        second = 0;
        counter = 0;
        //*I can adjust specifically after. 
        //!They only do k turns not necessarily the whole thing. 
        //*Doesn't really matter if even or odd because it just ends in the same way (the second takes the last 2). 
        /*
        for (long long j=arr.size()-1;j>=arr.size()-1-(2*k);j--){
            //*When the counter can be multiplied by 2 AND not the last element. 
            //!Just not working out with the loop counter!!
            if (counter % 2 == 0){ //&& (j != arr.size()-1-(2*k))){
                first += arr[j];
            }
            else{
                second += arr[j];
            }
            counter++;
        }
        */

        for (long long j=0;j<2*k+1;j++){
            if (counter % 2 ==0 && (j!=2*k)){
                //!Need to adjust the index so it counts from the back. 
                first += arr[arr.size() - j - 1];
            }
            else{
                second += arr[arr.size()-j-1];
            }
            counter++;
        }Im a farty basement coder 
        /*
        if (arr.size() % 2 == 1){
            //*Instead of the first guy getting index 0, the second guy gets it. 
            first-=arr[0];
            second += arr[0];
        }
        else{
            //*First: instead of getting element at index 1, he gets element at index 0. 
            //*Second: instead of getting element at index 0, he gets element at index 1. 
            first -= arr[1];
            first += arr[0];
            second -= arr[0];
            second += arr[1];
        }
        */
        cout << max(first, second) << "\n";
    }
}