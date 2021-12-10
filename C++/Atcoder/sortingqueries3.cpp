#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    priority_queue<long long> arr2;
    deque<long long> arr1;
    while (q--){
        long long num;
        cin >> num;
        if (num==1){
            long long x;
            cin >> x;
            arr1.push_back(x);
        }
        else if (num==2){
            if (arr2.empty()){
                cout << arr1[0] << endl;
                arr1.pop_front();
            }
            else{
                cout << -arr2.top() << endl;
                arr2.pop();
            }
        }
        else{
            for (auto e:arr1){
                arr2.push(-e);
            }
            arr1 = {};
        }
    }
}