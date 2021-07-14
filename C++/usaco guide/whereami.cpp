#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    long long n;
    cin >> n;
    string s;
    cin >> s;

    for (long long length=1;length<n;length++){
        set <string> hashset;
        bool ok = true;
        //*Need a speicific index for substringing. 
        //!I guess that isn't necessary since .subst doesn't give segmentation fault and cuts off. 
        for (long long start=0;start<n;start++){
            if (hashset.count(s.substr(start, length))==1){
                ok = false;
                break;
            }
            else{
                hashset.insert(s.substr(start, length));
            }
        }

        if (ok==true){
            cout << length << "\n";
            break;
        }
    }
}