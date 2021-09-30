#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    //*I guess 0 is a really iffy one so use 1 as lower bound. 
    long long largest =7, lowest = 1;
    long long x = rnd(lowest, largest), n = rnd(lowest, largest);
    cout << x<<" " << n << endl;
    for (long long i=0;i<n;i++){
        long long t = rnd(lowest, largest), f = rnd(lowest, largest);
        cout << t << " " << f << endl;
    }
}