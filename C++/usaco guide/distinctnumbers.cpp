#include <bits/stdc++.h>

using namespace std;

int main(){
    //*Counting sort is an interesting concept though..

    //*Can sort an array in decreasing order by sort(v.rbegin(), v.rend())

    //*I guess define functions kind of allow change in syntax (like the all() function)

    //!Can the below code be used to remove all duplicates?
    /*
    sort(all(vec));
vec.resize(unique(all(vec)) - vec.begin()); 
    */

   //*Either I can use a set or I can use the unique function. 

    long long n;
    cin >> n;
    set <long long> s;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        s.insert(temp);
        
    }
    cout << s.size() << endl;       
}