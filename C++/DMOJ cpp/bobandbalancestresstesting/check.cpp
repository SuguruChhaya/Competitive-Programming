#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream myAnswer("myAnswer");
    ifstream correctAnswer("correctAnswer");
    //ofstream check("check");
    long long a, b;
    myAnswer>>a;
    correctAnswer >> b;
    if (a != b){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
}