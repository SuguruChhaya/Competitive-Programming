#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map <int, int> a_map;
    vector <int> a, b, c;
    int temp;
    for (int i=0;i<n;i++){
        cin >> temp;
        if (a_map.count(temp)==0){
            a_map[temp] = 1;
        }
        else{
            a_map[temp] += 1;
        }
    }

    for (int i=0;i<n;i++){
        cin >> temp;
        b.push_back(temp);
    }

    for (int i=0;i<n;i++){
        cin >> temp;
        c.push_back(temp);
    }
    int result = 0;

    //*I can technically just store the values in a in a map so I can look up how many good values exist. 
    //!How can I get a wrong answer tho?
    for (int j = 0; j<n;j++){
        if (a_map.count(b[c[j]-1]) == 1){
            result += a_map[b[c[j]-1]];
        }
    }
    cout << result;
}