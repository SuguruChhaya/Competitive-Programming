#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

//!Let me just trust that this will work. 
long long modulo(long long a, long long b, long long n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

int main(){
    //*Since we are talking about an AND operator, as soon as we see one false then we know the answer is 0. 
    //**Convert to binary format and I guess there cannot be any matching 1s or else will become larger than 0. 
    //*The number of permutations can be insanely long if I just check naively. 
    //*We only need one permutation though. 
    //*Repeats are OK as long as number is not same. 

    //!If we have a certain number, we will already know the number of permutations since if we have 0 it could be 0 or 1 and if we have 1 it can only be 0. 
    //*Time limit is 1 second so shouldn't degrade to quadratic time. 
    //!Probably should return in near constant time for all the outputs. 
    //*I think the best way is to try coding up a brute force and observe whether there is a pattern. 

    long long int numTests, n, m;
    long long int a, b, c;
    cin >> numTests;
    
    for (long long i=0;i<numTests;i++){
        cin >> n >> m;
        //*We can really have however many matching ones as long as I have one 0 in there. 
        //*Like (0, 0, 1)
        //*Test cases for 9, 225 make sense but not the last one. It doesn't seem to be square root of anything and all. 
        //*The last number seems pretty random even looking at prime factor: 23 * 179 * 55441
        //*Never mind it was modulo so I pretty much hit the right number!!
        //!Need to find how many digits it fits in. 
        //!Actually it is exactly m digits!! Gives it in the problem statement right away!!
        //*There is a handy modulor property https://www.technicalkeeda.in/2020/10/modulo-property-for-competitive-programming.html
        //*But there is no way I can store 2^n so I need to do modulo at the same time. 
        //!Never mind this property is used for 
        a = (pow(2, n)-1);
        b = pow(a, m);
        c = b % 1000000007;
        cout << c << "\n";
    }

    

}



/*
int main(){
    long long int numTests, n, m;
    long long int a, b, c;
    cin >> numTests;
    
    //*Logically, it could only be an overflow error. I mean how can even a long long store a value like 2 ^(10^6)?
    //*
    for (long long i=0;i<numTests;i++){
        cin >> n >> m;
        //*Literally no way I can store value without modding in between. 
}