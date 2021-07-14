#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    //*Finally kind of get it. 
    //*We don't know which one is entry and exit so we have to simulate both of the cases. 
    //*I guess I could create a double length string for both directions. Iterate on the right side. 

    //!Basically if there is only one element in between we got it. 
    //*Applies for the oppoisite but not creating (a, b) and (b, a).

    //set <vector <char, char>> pairs;

    vector <long long> location;
    for (long long i=0;i<26;i++){
        location.push_back(-1);
    }
    string s;
    cin >> s;
    //*Store the starting one for all elements and go right for all of them. 

    for (long long i=0;i<52;i++){
        if (location[(int)s[i]-(int)'A']==-1){
            location[(int)s[i]-(int)'A'] = i;
        }
    }
    long long result = 0;
    //*I could check for every single one without using set. 
    for (long long i=0;i<26;i++){
        for (long long j=i+1;j<26;j++){
            //*Start from the next index or else it will immediately recognize. 
            long long curr = location[i] + 1;
            long long numSeen = 0;
            while (s[curr] != (char) (i+(int) 'A')){
                if (s[curr]==(char) (j + (int) 'A')){
                    numSeen++;
                }
                curr++;
            }
            if (numSeen == 1){
                result++;
            }
        }
    }

    cout << result << endl;
}