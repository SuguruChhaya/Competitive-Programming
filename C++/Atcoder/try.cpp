#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
/*
int main(){
    set <string> s;
    s.insert("abba");
    s.insert("aabb");

    //*I can access the elements linearly like this. 
    string second = *next(s.begin(),1);
    cout << second;

    map<int, int> a= {{1, 2}, {2, 4}};
    cout << a.size()<< "yo" << endl;

    string temp;
    temp = 'a' * 4;
    cout << temp;
}
*/
int main() {
    set <pair <long long, string>> hashset;
    hashset.insert({5, "a"});
    hashset.insert({3, "abc"});
    auto it = hashset.begin();
    it++;
    pair <long long, string> temp = *it;
    cout << temp.first;
}
