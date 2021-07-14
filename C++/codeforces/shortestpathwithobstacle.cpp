#include <bits/stdc++.h>

using namespace std;

int main(){
    //*The only special case that won't work is when F is in the smack middle between A and B. 

    long long t;
    cin >> t;
    vector <long long> result;
    for (long long i=0;i<t;i++){
        long long x_a, y_a, x_b, y_b, x_f, y_f;
        cin >> x_a >> y_a >> x_b >> y_b >> x_f >> y_f;

        //*Same x_value and f_is in the smack middle. 
        if (x_a==x_b && x_b==x_f){
            //!Again, C++ doesn't want 3 numbersw in this inequality thing. 
            if ((y_a < y_f && y_f < y_b) || (y_b < y_f && y_f< y_a)){
                cout << abs(y_a-y_b) + 2 << endl;
            }
            else{
                cout << abs(y_a-y_b) << endl;
            }
        }
        else if (y_a==y_b && y_b == y_f){
            if ((x_a < x_f && x_f< x_b) || (x_b < x_f && x_f< x_a)){
                cout << abs(x_a-x_b) + 2 << endl;
            }
            else{
                cout << abs(x_a-x_b) << endl;
            }
        }
        else{
            cout << abs(x_a-x_b) + abs(y_a-y_b) << endl;
        }

    }
}