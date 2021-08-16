#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Honestly, this question might be somewhat more approachable..
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        //cout << 1 << endl;

        //!Really, I think it is all about a little bit of math and checking the locations. 
        double numerator = 0;
        double pi = 2*acos(0.0);
        double denominator = pow((r2 - r3), 2) * pi;

        //*First check the inner. 
        //*For R3 to be inside of R1, the radius must be smaller. 
        if (r3 < r1){
            numerator += pow((r3-r1), 2) * pi;
        }

        //*Now check outside. 
        if (r2 - r3 >= r1+r3){
            //*This area is a little more complicated to calculate. 
            numerator += pow((r2-r3), 2) * pi - pow((r1+r3), 2) * pi;
        }

        cout << numerator / denominator << endl;

    }
}