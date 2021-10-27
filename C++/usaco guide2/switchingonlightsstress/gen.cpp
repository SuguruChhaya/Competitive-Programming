#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}
int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 5), m = rnd(1, n*n);
    set <vector <long long>> used;
    cout << n << " " << m << endl;
    for (long long i=0;i<m;i++){
        long long x = rnd(1, n), y = rnd(1, n);
        while (used.count({x, y})){
            x = rnd(1, n), y = rnd(1, n);
        }
        used.insert({x, y});
        long long a = rnd(1, n), b = rnd(1, n);
        cout << x << " " << y << " " << a << " " << b << endl;
    }

}