#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 5), m = rnd(2, 5);
    cout << n << " " << m << endl;
    for (long long i=0;i<n;i++){
        long long f = rnd(1, m), s=rnd(1, m);
        while (f==s){
            s = rnd(1, m);
        }
        cout << f << " " << s << endl;
    }
    
}