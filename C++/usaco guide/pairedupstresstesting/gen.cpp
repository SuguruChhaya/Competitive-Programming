#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long limit = 20;
    long long m = rnd(1, limit);
    //*They have to add up to m. Can be pretty random. 
    long long n=rnd(1, limit), numCows = 0;

    cout << n << endl;
    for (long long i=0;i<n;i++){
        long long a, b;
        a = rnd(1, m-numCows);
        b = rnd(1, limit);
        if (i==n-1){
            //*We have to make sure it adds up. 
            a = m-numCows;
        }
        numCows+= a;
        cout << a << " " << b << endl;
    }
}