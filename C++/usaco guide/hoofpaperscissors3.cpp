#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long> (2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    long long result = 0;
    vector <long long> winning = {-1, 3, 1, 2};
    for (long long a=1;a<=3;a++){
        for (long long b=1;b<=3;b++){
            for (long long c=1;c<=3;c++){
                if (a!=b&&b!=c&&a!=c){
                    long long temp = 0;
                    vector <long long> matching = {-1, a, b, c};
                    for (auto e:arr){
                        if (winning[matching[e[0]]]==matching[e[1]]){
                            temp++;
                        }
                    }
                    /*
                    if (temp==6){
                        cout << "";
                    }
                    */
                    result = max(result, temp);
                }
            }
        }
    }
    cout << result << endl;
}