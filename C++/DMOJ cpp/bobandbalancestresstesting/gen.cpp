#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}
//!OK the specifically tricky part about this program is that 
//*The first value has to be the same. 
int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 6);
    cout << n << endl;
    for (long long i=0;i<2*n;i++){
        long long x = rnd(1, 10);
        cout << x << " ";
    }
    cout << endl;
}