#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> arr1 = {1, 2, 3};
    vector <int> arr2;
    arr2 = arr1;
    arr1[1] = 5;
    //!C++ arrays are not mutable but why is there such a hard time?
    cout << arr2[1] << "\n";
}