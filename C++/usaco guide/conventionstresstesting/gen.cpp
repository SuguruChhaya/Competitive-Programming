#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n=rnd(1, 10), m=rnd(1, 10), c=rnd(ceil(m/n), ceil(m/n)+3);
    cout << n << " " << m << " " << c << endl;
    for (long long i=0;i<n;i++){
        long long x = rnd(1, 10);
        cout << x << endl;
    }
    
}