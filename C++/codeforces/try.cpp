#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> arr1 = {1, 2, 3};
    vector <int> arr2;
    arr2 = arr1;
    arr1[1] = 5;
    //!C++ arrays are not mutable but why is there such a hard time?
    cout << arr2[1] << "\n";

    cout << (int) 'a';

    vector <vector <long long>> arr;
    arr.push_back({2, 1});

    sort(arr[0].begin(), arr[0].end());

    cout << arr[0][0] << endl;

    //!Is sorted correctly. 

    set <long long>s = {0}; 
    s.erase(1);
    cout << s.size() << endl;
}