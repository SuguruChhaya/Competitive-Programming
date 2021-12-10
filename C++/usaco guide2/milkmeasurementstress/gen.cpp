#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 10), g = rnd(1, 10);
    cout << n << " " << g << endl;
    //!only 1 change per second -> maybe reduce time?
    set <long long> s;
    for (long long i=0;i<n;i++){
        long long time = rnd(1, 10);
        while (s.count(time)){
            time  = rnd(1, 10);
        }
        s.insert(time);
        long long change = rnd(-10, 10);
        while (change==0){
            change = rnd(-10, 10);
        }
        long long cow=rnd(1, n);
        cout << time << " " << cow << " " << change << endl;
    }
}