//*I think of common issue with recursion so Imma use sol. 

#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, m;
    cin >> n >> m;
    vector <vector <long long>> arr (n+1, vector <long long>(2));
    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        arr[a][b]=1;
    }
}