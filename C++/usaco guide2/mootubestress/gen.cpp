#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}
vector<bool> visited;
bool dfs(map<long long, vector<long long>> d){
    
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 10), q = rnd(1, 10);
    cout << n << " " << q << endl;
    //!Kind of a hard one to generate. 
    //*Has to be reachable in 
    bool ok = false;
    while (!ok){
        set <long long> used;
        map <long long, set <long long>> d;
        for (long long i=0;i<n-1;i++){
            long long p = rnd(1, n), q = rnd(1, n);
            while (d.count({p, q} || d.count(q, p) || p==q)){
                p = rnd(1, n), q = rnd(1, n);
            }
            //*Also the pair couldn't have existed before. 
            
        }
        //!The numbers are a little different. 
        visited.resize(n, 0);
        dfs(d);
    }

    for (long long i=0;i<q;i++){
        long long k = rnd(1, 10), v = rnd(1, 10);
        cout << k << " " << v << endl;
    }
}