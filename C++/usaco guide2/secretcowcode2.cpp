#include <bits/stdc++.h>
using namespace std;
string s;
char charAt(long long k, long long total){
    if (k<s.size()){
        //?Could it be that we got to a negative k?
        return s[k];
    }
    
    if (k<total/2){
        return charAt(k, total/2);
    }
    else{
        //!No real idea what this is doing...
        return charAt((k%(total/2)-1), total/2);
    }
    
}

int main(){
    //The solution uses 1-indexing. 
    //freopen("cowcode.in", "r", stdin);
    //freopen("cowcode.out", "w", stdout);
    long long n;
    cin >> s >> n;
    //Brute force it first and then create a greedy.
    long long total = s.size();
    while (total<n){
        total *= 2;
    }
    cout << charAt(n-1, total) << endl;
}