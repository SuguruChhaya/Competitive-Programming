#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 15);
    cout << n << endl;
    vector <char> v = {'F', 'O', 'X'};
    for (long long i=0;i<n;i++){
        long long temp = rnd(0, 2);
        cout << v[temp];
    }
    cout << endl;
}