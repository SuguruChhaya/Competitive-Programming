#include <bits/stdc++.h>
using namespace std;

int main(){
    //*My stupid hypothesis was blatantly wrong. 
    //*Could I run a BFS??
    //!Cannot do because every new time there is 100 new possibilities. 
    //*The number of permutations is gonna be 100! which is way outta hands. 
    //!No matter what I move, a 7 is position 6 has to manually moved. 
    //!The greatest difference from original position matters too. 
    //*If 1 is at the back, I need to move all of them out of the way to bring 1 to the front. 

    //!Never thought about it like that!!. 
    //*So I can just find the number of sorted parts from the end and subtract it from total length!!. 

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (long long i=0;i<n;i++){
        bool ok = true;
        for (long long j=i+1;j<n;j++){
            //*If the next is smaller than prev, it is not sorted
            if (arr[j] < arr[j-1]){
                ok = false;
                break;
            }
        }
        if (ok){
            cout << i << endl;
            break;
        }
    }
}