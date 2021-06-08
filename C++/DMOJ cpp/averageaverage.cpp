#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    //!Hate these types of mini-speed improvement necessary questions.
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;//*I see subrepository hidden so I can cancel that. 
    int x;
    vector <int> arr;
    //*Need to get only one line. 
    int temp = 0;
    int currSum = 0;
    vector <int> table;

    while (temp < n){
        cin >> x;
        arr.push_back(x);
        temp++;
        currSum += arr[arr.size()-1];
        table.push_back(currSum);
    }

   

    //!I guess the whole point is to do this in one pass. 
    //*Once I hit the last element of a query
    //!I can add to the prefix sum after I receive the query values and I can check whether there is a query upto that range. 
    //!NO, I need to run separate loop but create prefix array while reading the input. 

    int l, r;
    for (long i=0;i<q;i++){
        cin >> l >> r;
        cout << floor((table[r-1] - table[l-1] + arr[l-1]) / (r-l+1)) << "\n";
    }
}