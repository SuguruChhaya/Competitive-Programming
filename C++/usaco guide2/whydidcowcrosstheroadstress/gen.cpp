#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    
    long long c = rnd(1, 10), n = rnd(1, 10);
    cout << c << " " << n << endl;

    
    for (long long i=0;i<c;i++){
        long long x = rnd(1, 10);
        //!Isn't necessarily distinct. 
        cout << x << endl;
    }

    //*Create for n

    for (long long i=0;i<n;i++){
        long long x = rnd(1, 10), y=rnd(x, 10);
        cout << x << " " << y << endl;
    }
}