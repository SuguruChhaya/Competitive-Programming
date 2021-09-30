#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

/*
int main(){
    long long numTests;
    long long a, b, c, d;
    long long daysContinue;
    long long lastArithmetic;
    long long totalArithmetic;
    long long remainder;
    cin >> numTests;
    //!This stupid arithmetic problem giving me WA. 
    for (long long i=0;i<numTests;i++){
        cin >> a >> b >> c >> d;

        //*I think a simulation will TLE so I need to do it mathy way. 
        //*Number of days a certain cost applies remains constant. Except of the case of days running out in the middle. 
        //!Calculating the arithmetic series is not that hard. 
        //*I could add the exception last. 
        //*All the others form arithmetic and multiply by days apply. 
        
        daysContinue = a / b; //*Should give an integer since no float. 
        remainder = a % 2;
        //*For the 5 2 1 2 example, we have to multiply by daysConinue-1 since that is the actual last. 
        if (remainder == 0){
            //!I guess it might not make a difference if the dayscontinue. 
            lastArithmetic = c + ((daysContinue-1) * d);
        
        //*Multiply by some kind of number...
        
        }
        else{
            lastArithmetic = c + ((daysContinue-1) * d);
        }
        //*Total numbers in the arithmetic is (daysContinue * interval: b)
        totalArithmetic = ((c + lastArithmetic) *  (daysContinue * b) / 2);
        //!Have to add whatever we didn't add in the first go. 

        //!Maybe the reason is because I didn't consider the C value factored outside the arithmetic!!
        cout << (totalArithmetic * c) + (remainder * (lastArithmetic + d)) << "\n";

    }
}
*/

int main(){
    //*Let me take a more normal arithmetic approach. 
    //*D*P is guaranteed. 
    long long numTests;
    long long a, b, c, d;
    long long daysContinue;
    long long lastArithmetic;
    long long totalArithmetic;
    long long remainder;
    //cin >> numTests;
    long long currInterval = 0;
    long long currPrice;
    long long result;
    //for (long long j=0;j<numTests;j++){
        currInterval = 0;
        result = 0;
        cin >> a >> b >> c >> d;
        //*Let me get points by the naive solution first. 
        currPrice = c;
        for (long long i=1;i<=a;i++){
            result+=currPrice;
            currInterval++;
            if (currInterval==b){
                currPrice += d;
                currInterval = 0;
            }
        }
        cout << result <<"\n";

    //}
}
