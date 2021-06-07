#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    long long numTests;
    cin >> numTests;
    double a, b, c, d;
    
    for (long long i=0;i<numTests;i++){
        //*Not guaranteed to be divisible. 
        cin >> a >> b >> c >> d;
        cout << ceil(c / a) + ceil (d/b) << "\n";
    }
    

}