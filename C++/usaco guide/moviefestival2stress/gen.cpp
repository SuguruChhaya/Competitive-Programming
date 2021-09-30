#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}


int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    //*Just by looking at the restrictions, doesn't seem like k will be larger. 
    long long n = rnd(1, 10);
    long long k = rnd(1, n);
    cout << n << " " << k;
    for (long long i=0;i<n;i++){
        long long a = rnd(1, 9), b = rnd(a+1, 10);
        cout << a << " " << b << endl;
    }
}