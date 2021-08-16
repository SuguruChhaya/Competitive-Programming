#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(long long argc, char* argv[]){
    long long seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(100000, 1000000);
    cout << n << endl;
    for (long long i=0;i<n;i++){
        long long x = rnd(1, 1000000000);
        if (i==0){
            cout << x;
        }
        else{
            cout << " " << x;
        }
    }
    cout << endl;
}