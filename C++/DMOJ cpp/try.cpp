#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    /*
    int a = 2;
    int b = 5;

    //cout << floor((a+b) / 2);

    long c = 2;
    int d [3] = {1, 2, 3};
    //!Long item must not have any issues accessing but..
    vector <int> arr = {1, 3, 2};
    //!Somehow the sorting isn't working well when I add ints. 
    //*Have to sort by begin +
    sort(arr.begin()+1, arr.begin()+3);
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
    cout << d[c];
    */

    long long a = 0;
    string s = "AAABBB";
    while (s[a]=='A'){
        a++;
    }
    //!Supposed to be working...
    if (a==0){

    }
    else{
        while (s[a]=='B'){
            a++;
        }
    }
    cout <<a;
}