#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    set <vector <long long>> order, value;
    vector <bool> removed (q, 0);
    long long orderNum = 0;
    bool sortExists = 0;
    //!Kind of misunderstood the problem. 
    while (q--){
        long long num;
        cin >> num;
        if (num==1){
            long long x;
            cin >> x;
            order.insert({orderNum, x});
            value.insert({x, orderNum});
            orderNum++;
        }
        else if (num==2){
            if (sortExists){
                auto it = value.begin();
                while (removed[(*it)[1]]){
                    it++;
                }
                cout << (*it)[0] << endl;
                removed[(*it)[1]] = 1;
            }
            else{
                auto it = order.begin();
                while (removed[(*it)[0]]){
                    it++;
                }
                cout << (*it)[1] << endl;
                removed[(*it)[0]] = 1;
            }
            sortExists = 0;
        }
        else if (num==3){
            sortExists = 1;
        }
    }
}