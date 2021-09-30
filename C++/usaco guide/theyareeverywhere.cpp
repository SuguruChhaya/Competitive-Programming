#include <bits/stdc++.h>
using namespace std;

bool all_exists(map <char, long long> d, set <char> s){
    for (auto e:s){
        if (d.count(e)==0 || d[e]==0){
            return false;
        }
    }
    return true;
}

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    //*Basically read all the characters into a set to check whether they all exists. 
    //!I could use a map.
    //*Probably easier to use map instead of multiset.  
    set <char> c;
    map <char, long long> d;
    for (long long i=0;i<n;i++){
        c.insert(s[i]);
    }
    /*
    long long left = 0, right = n-1, ans = n;
    while (left<=right){
        if (d[s[left]]>1){
            //*Means we can subtract from the left. 
            d[s[left]]--;
            left++;
        }
        //*If the 2 values are the same and all the important values are concentrated on the left side, incrementing the left side wouldn't be good idea. 
        //*AbabbbbbbbbbA
        if (d[s[right]]>1){

        }   
    }
    */
    //!I could use a multiset since occurence matters
    //!But then I need to check whether multiset==set?
    long long left=0, right=0, ans=n;
    while (left <n && right <n){
        d[s[right]]++;
        right++;
        while (all_exists(d, c)){
            ans = min(ans, right-left);
            //*What if s[left] doesn't exist? 
            
            d[s[left]]--;
            left++;
        }   
        //!After I reach the end, I will not be able to just shrink the left side. 
        //*I think I should create inner loop where I try to erase as many from the left side. 

    }
    cout << ans << endl;
}