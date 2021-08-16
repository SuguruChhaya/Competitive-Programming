#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a >= b && c >= d){
        cout << "Stay home" << "\n";
    }
    else if (a < b && c < d){
        cout << "Go to the department store" << "\n";
    }
    else if (a < b){
        cout << "Go to the grocery store" << "\n";
    }
    else if (c < d){
        cout << "Go to the pharmacy" << "\n";
    }
}