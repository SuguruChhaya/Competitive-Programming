#include <bits/stdc++.h>
using namespace std;

long long rnd(long long a, long long b){
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
	long long seed = atoi(argv[1]);
	srand(seed);
	long long w = rnd(1, 100);
	cout << w << endl;
}