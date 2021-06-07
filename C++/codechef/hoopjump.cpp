#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //*Since 10^5, definetely better not to simulate the whole thing. 
    long long numTests;
    cin >> numTests;
    long long n;
    //double result;
    for (long long i=0;i<numTests;i++){
        cin >> n;
        //result = n/2;
        cout << ceil(n / 2.0) << "\n";
    }
}