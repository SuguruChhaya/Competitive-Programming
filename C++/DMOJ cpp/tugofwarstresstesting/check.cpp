#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input_file", "r", stdin);
    freopen("verdict_file", "w", stdout);
    
    ifstream brutein("correctAnswer");
    ifstream myin("myAnswer");

    //*Don't know size so keep reading and adding to vector. 
    vector <long long> b, m;
    long long temp;
    
    while (brutein>>temp){
        b.push_back(temp);
    }
    while (myin>>temp){
        m.push_back(temp);
    }
    if (b==m){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}