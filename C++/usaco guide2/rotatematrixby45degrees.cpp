#include <bits/stdc++.h>
using namespace std;

int main(){
    	//ifstream fin("lazy.in");
	//fin >> n >> k;
    //!The maximum index of the matrix is 2*n-2. So size is 2*n-1
    
    long long n;
    cin >> n;
    vector <vector <long long>> arr (2*n-1, vector <long long>(2*n-1, 0));
	// rotate the matrix 45 degrees
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> arr[i+j][n-i+j-1];
}