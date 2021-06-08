#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <vector>
using namespace std;

int main(){
    map <int, int> d;
    d[1] = 2;
    d[3] = 5;

    //*I can use iterator maybe to paste all keys into a vector. 

    for (auto x:d){
        cout << x.first << " " << x.second;
    }
    vector <int> arr = {2, 3};
    //*Need to use iterator to erase. 
    arr.erase(arr.begin()+1);
    cout << arr.size() << endl;
    
    //*I can access the smallest elements in set using iterator. 
    set <int> hashset;
    hashset.insert(4);
    hashset.insert(2);
    hashset.insert(5);
    //*I think auto just detects the type of iterator. 
    auto it = hashset.begin();
    for (int i=0;i<2;i++){
        it++;
    }
    //*Basically can access any element in set. 
    cout << *it;

    //*Who needs complex iterators tho?
    //*But a foreach loop could be helpful. 

    vector <int> arr2 = {1, 2, 3};
    for (int element:arr2){
        cout << element;
    }

    //!Pairs are often helpful to store data of different types. 
    pair <vector <int>, string> a = {arr2, "abc"};
    cout << a.second;

    //*Tuples can also contain separate data types. 
    tuple <int, string> t{1, "abc"};
    get <0>(t) = 2;
    cout << get <0> (t);
}