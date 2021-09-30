//*The correct solution for the problem:
#include <iostream>
#include <vector>

using namespace std;

/**
 * @author Qi Wang
 * (detemplifying courtesy of Kevin Sheng)
 */
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
    //*Uses a vector instead of a dictionary. 
	vector<long long> M(N);
	long long psums = 0;
	M[psums] = 1;
    vector <long long> arr;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		psums += a;
		// Remember to account for negative sums
		M[(psums % N + N) % N]++;
        arr.push_back((psums % N + N) % N);
	}
    for (long long i=0;i<N;i++){
        cout << arr[i] << endl;
    }
	long long ans = 0;
	for (long long x : M) {
		/*
		 * Calculating the # of pairs.
		 * This calculates the pairs without
		 * duplicates and reverse groups.
		 */
		ans += x * (x - 1) / 2;
	}
	cout << ans << endl;

    //!I don't get it. Why would a brute force of creating all the prefix sums not work??
    //*I need a specific example of where this really matters. 

}
//!My own answer for this case makes sense. 
//*Just need to find what I am missing. 
/*
Good checking testcase

10
2 1 -3 2 -7 7 -2 6 9 -4

*/