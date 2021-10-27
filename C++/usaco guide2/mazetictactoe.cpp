#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <vector <vector <char>>> arr(n, vector <vector <char>>(n, vector <char>(3)));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j][0] >> arr[i][j][1] >> arr[i][j][2];
        }
    }
    deque <tuple<vector<long long>, vector <vector <bool>>, vector <vector <bool>>>> q;
    set <vector <vector <char>>> ans;
    vector <vector <bool>> temp1, temp2 (n, vector <b)
}