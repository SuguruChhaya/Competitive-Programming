#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;
    map <long long, long long> a_map;
    vector <long long> a, b, c;
    long long temp;
    for (long long i=0;i<n;i++){
        cin >> temp;
        if (a_map.count(temp)==0){
            a_map[temp] = 1;
        }
        else{
            a_map[temp] += 1;
        }
    }

    for (long long i=0;i<n;i++){
        cin >> temp;
        b.push_back(temp);
    }

    for (long long i=0;i<n;i++){
        cin >> temp;
        c.push_back(temp);
    }
    long long result = 0;

    //*I can technically just store the values in a in a map so I can look up how many good values exist. 
    //!How can I get a wrong answer tho?
    for (long long j = 0; j<n;j++){
        if (a_map.count(b[c[j]-1]) == 1){
            result += a_map[b[c[j]-1]];
        }
    }
    cout << result;
}