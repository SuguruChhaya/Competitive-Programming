#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 10);
    for (long long i=0;i<n;i++){
        long long p = rnd(1, 10), c = rnd(1, 10);
        cout << p << " " << c << endl;
        long long a = rnd(0, p-1), b = rnd(0, p-1);
        while (b==a){
            b = rnd(0, p-1);
        }
        cout << a << " " << b << endl;
    }
    cout << 0 << " " << 0 << endl;
}