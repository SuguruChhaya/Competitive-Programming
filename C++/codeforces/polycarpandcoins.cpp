#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        //*If divisible by 2, 
        //!Just because it is odd or even doesn't mean anything. 

        //*Try to divide into 3. 
        long long num1, num2, num3;
        if (n % 3==0){
            num1=num2=num3=n/3;

            cout << num1 << " " << num2 << endl;
        }
        else{
            num1 = n / 3;
            num2 = (n - num1) / 2;
            num3 = n - num1 - num2;
            //cout << num1 << " " << num2 << " " << num3 << endl;
            //*There must be 2 values that are equal. 
            if (num1==num2){
                cout << num3 << " " << num1 << endl;
            }
            else if (num2==num3){
                cout << num1 << " " << num2 << endl;
            }
            else if (num1==num3){
                cout << num2 << " " << num1 << endl;
            }
        }
    }
}