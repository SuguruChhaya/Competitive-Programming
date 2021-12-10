#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 8);
    cout << n << endl;
    for (long long i=0;i<n;i++){
        cout << rnd(1, 10) << endl;
    }
}