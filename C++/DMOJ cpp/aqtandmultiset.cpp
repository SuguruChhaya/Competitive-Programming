#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //!Isn't there only 1 real value the XOR can be? 
    //*I could get a larger number by xoring a smaller number compared to xoring a larger number. 
    
    //*Try to match the numbers into what it XORS into and adjust that for everything else. 

    //!Do I guess I should create a multiset on my own. 
    multiset<long long> a, b;
    for (long long i=0;i<2*n+1;i++){
        long long temp;
        cin >> temp;
        a.insert(temp);
    }
    for (long long i=0;i<2*n+1;i++){
        long long temp;
        cin >> temp;
        b.insert(temp);
    }
    long long large = 999999999999999999;
    long long result = large;
    //*Focus on the first element of a set and pair it with every element in b_set.
    for (auto b_element:b){
        //*Calculate the XOR value.
        //!Don't XOR but rather calculate what number I have to XOR it to get the number. 
        //*Does the same thing I guess. 
        long long temp = *(a.begin()) ^ b_element;
        multiset <long long> next;
        for (auto a_element:a){
            next.insert(a_element ^ temp);
        }
        if (next==b){
            result = min(result, temp);
        }
    }
    if (result==large){
        cout << -1 << endl;
    }
    else{
        cout << result << endl;
    }
    

}