#include <bits/stdc++.h>

using namespace std;

int main(){
    long long q;
    cin >> q;

    for (long long i=0;i<q;i++){
        long long n, k;
        cin >> n >> k;

        vector <long long> positions, temperatures;
        for (long long j=0;j<k;j++){
            long long temp;
            cin >> temp;
            positions.push_back(temp);
        }
        for (long long j=0;j<k;j++){
            long long temp;
            cin >> temp;
            temperatures.push_back(temp);
        }   

        //!Need to make sure it is 1-indexed. 

        //!Shit, I guess there is no way it is gonna pass with brute force and no creativity lol. 

        //*Could try practicing this one...

        for (long long j=1;j<=n;j++){
            //*Create the min. 
            long long m = 99999999999999;
            for (long long h=0;h<k;h++){
                long long temp = temperatures[h] + abs(positions[h]-j);
                m = min(m, temp);
            }

            cout << m << " ";
        }
        cout << endl;
    }

}