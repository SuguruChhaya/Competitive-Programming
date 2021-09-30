#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Cannot I will have to mark it in a way that I can instantly lookup based on the query. 
    long long L, q;
    cin >> L >> q;
    set <long long> s = {0, L};
    for (long long i=0;i<q;i++){
        long long c, x;
        cin >> c >> x;
        if (c==1){
            s.insert(x);
        }
        else{
            s.insert(x);
            for (auto e:s){
                cout << e << endl;
            }
            auto it = s.find(x);
            auto prev = it--;
            auto next = it++;
            cout << *next - *prev << endl;
        }
    }
}