#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    //!I just need an example where there is a seg error. 
    int seed = atoi(argv[1]);
    srand(seed);
    long long n = rnd(1, 10);
    cout << n << endl;
    set <vector <long long>> used;
    for (long long i=0;i<n-1;i++){
        //*This way we won't get a duplicate. 
        //!Always in ascending order. 
        //!I think I have to explicitly check whether there will be a valid value of b
        
        long long a = rnd(1, n), b;
        while (a+1>n){
            a = rnd(1, n);
        }
        b = rnd(a+1, n);
        vector <long long> temp = {a, b};
        while (used.count(temp)){
            a = rnd(1, n), b = rnd(a+1, n);
            temp = {a, b};
            
        }
        cout << a << " " << b << endl;
    }
}