#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 10), m = rnd(1, 5);
    cout << n << " " << m << endl;
    long long prevEnd = 0;
    for (long long i=0;i<m;i++){
        long long a = rnd(prevEnd+1, prevEnd+5), b=rnd(a, a+5);
        prevEnd = b;
        cout << a << " " << b << endl;
    }
    //!Hard question to generate valid testcases. 
    
}