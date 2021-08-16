#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    //*Number of testcases really shouldn't be considered when generating testcases. 
    long long n = rnd(1, 20);

    //!I think not outputting anything will cause problems. 
    //*Preferable if I could do the checking in bash. 
    
    //!Need to make sure t is even later on. 
    long long l = rnd(0, n);
    long long r = n - l;
    cout << n << " " << l << " " << r << endl;
    for (long long i=0;i<n;i++){
        //*Generate a random number within range. 
        long long x = rnd(1, n);
        if (i==0){
            cout << x;
        }
        else{
            cout << " " << x;
        }
    }
    cout << endl;
}