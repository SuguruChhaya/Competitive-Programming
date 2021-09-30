#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    long long t = rnd(1, 2);
    while (t--){
        int seed = atoi(argv[1]);
        srand(seed);
        long long p = rnd(1, 10), c = rnd(1, p * (p-1) / 2);
        cout << p << " " << c << endl;
        for (long long i=0;i<c;i++){
            long long a = rnd(0, p-1), b = rnd(0, p-1);
            while (a==b)
            {
                a = rnd(0, p-1), b = rnd(0, p-1);
            }
            //*Ensure that they are different. 
            cout << a << " " << b << endl;
        }
    }
}