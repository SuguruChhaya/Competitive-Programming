#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long D, d, P, Q;
    D = rnd(1, 100);
    d = rnd(1, D);
    P = rnd(1, 20);
    Q = rnd(1, 20);
    cout << D << " " << d << " " << P << " " << Q << endl;
}