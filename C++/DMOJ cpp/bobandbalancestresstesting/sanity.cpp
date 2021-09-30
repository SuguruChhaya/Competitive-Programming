#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream a("input_file");
    ifstream b("myAnswer");
    ifstream c("correctAnswer");


    long long n;
    a >> n;
    cout << "Input: " << endl;
    cout << n << endl;
    for (long long i=0;i<2*n;i++){
        long long temp;
        a >> temp;
        cout << temp << " ";
    }
    cout << endl;
    long long d;
    b >> d;
    cout << "My answer: " << d << endl;
    long long e;
    c >> e;
    cout << "Correct answer: " << e << endl;
}