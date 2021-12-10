#include <bits/stdc++.h>
using namespace std;

int main(){
    set <long long> s = {1, 2};
    auto it = s.end();
    it--;
    s.erase(it);
    for (auto e:s){
        cout << e << endl;
    }
}