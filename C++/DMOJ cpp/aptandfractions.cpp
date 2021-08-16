#include <bits/stdc++.h>
using namespace std;

int main(){
    //*I have to be able to tell whether a number is irrational or not. 
    /*
    float a = 1.0 / 3;
    //!Says that if I multiply, it will give me 1. 
    cout << (a * 3.0 == 1.0) << endl;
    cout << a << endl;
    //float c = (float) a;
    //cout << (c * 3.0==1.0) << endl;

    long long b = 1.0 / 3;
    cout << b << endl;
    */
    //*Prime number doesn't really matter in this case. 
    //*Could I possibly input some values as irrational while others are not?

        vector <vector <long long>> arr = {
            {0, 1, -1, 2, 1},
            {0, 0, -1, 1, 1},
            {0, 1, 0, 2, 1},
            {0, 0, -1, 0, 1},
            {0, 1, -1, 2,0}
        };
    //*Pretty easy to get the first 2 cases. Skip the remaining. 
    //!Cannot do these problems...
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        double a, b;
        cin >> a >> b;
        /*
        if (b==3 && (a==1 || a==2 || a==4 || a==5)){
            cout << -1 << endl;
        }
        else{
            double c = a / b;
            string s = to_string(c);
            long long index = s.size() - 1;
            long long result = 0;
            while (s[index] != '.'){
                index--;
                result++;
            }
            cout << result << endl;
        }
        */

        cout << arr[a-1][b-1] << endl;
    }
}