#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(2, 10), b = rnd(2, 10);
    cout << n << " " << b << endl;
    cout << 0 << " ";
    for (long long i=1;i<n-1;i++){
        cout << rnd(0, 10) << " ";
    }
    cout << 0 << endl;
    for (long long i=0;i<b;i++){
        cout << rnd(0, 10) << " " << rnd(1, n-1) << endl;
    }
}