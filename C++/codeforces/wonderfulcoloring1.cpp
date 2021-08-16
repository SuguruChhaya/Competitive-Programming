#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        string s;
        cin >> s;
        //*2^50 is not good. 
        //!Need a better way to color. 
        //*OK so if the length of the string is odd, there will be at least one letter that won't be painted. 
        //*OK so we can store all the characters in a dict. 
        //*Really, isn't it the number of unique letters I can get??
        //*No, if the occurence is 2 or under, I could paint it in different colors. 
        //*I can keep adding the number of letters I can cover, divide by 2 and get the answer?

        map <char, long long> d;
        for (auto c:s){
            if (d.count(c)==1){
                d[c]++;
            }
            else{
                d.insert({c, 1});
            }
        }
        long long total = 0;
        for (auto p:d){
            long long two = 2;
            total += min(two, p.second);
        }

        cout << total / 2 << endl;

    }
}