#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 5);
    cout << n << endl;
    set <vector<long long>> visited;
    for (long long i=0;i<n;i++){
        long long x = rnd(0, 10), y = rnd(0, 10); 
        while (visited.count({x, y})){
            x = rnd(0, 10), y = rnd(0, 10);
        }
        visited.insert({x, y});
        cout << x << " " << y << endl;
    }
}