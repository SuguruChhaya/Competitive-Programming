#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(2, 5), m = rnd(1, 5);
    cout << n << " " << m << endl;
    vector<char> chars = {'S', 'D'};
    for (long long i=0;i<m;i++){
        char c = chars[rnd(0, 1)];
        long long a = rnd(1, n), b = rnd(1, n);
        while (a==b){
            a = rnd(1, n), b = rnd(1, n);
        }
        cout << c << " " << a << " " << b << endl;
    }
}