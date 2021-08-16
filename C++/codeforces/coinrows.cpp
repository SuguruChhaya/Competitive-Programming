#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long m;
        cin >> m;
        vector <long long> a, b, prefix_a, prefix_b;
        //!I think I could technically use a prefix sum but I think adding and subtracting won't be big deal.
        for (long long j=0;j<m;j++){
            long long temp;
            cin >> temp;
            a.push_back(temp);
            if (j==0){
                prefix_a.push_back(temp);
            }
            else{
                prefix_a.push_back(prefix_a[prefix_a.size()-1] + temp);
            }
        }
        for (long long j=0;j<m;j++){
            long long temp;
            cin >> temp;
            b.push_back(temp);
            if (j==0){
                prefix_b.push_back(temp);
            }
            else{
                prefix_b.push_back(prefix_b[prefix_b.size()-1] + temp);
            }
        }

        for (auto e: prefix_a){
            cout << e << endl;
        }
        for (auto e: prefix_b){
            cout << e << endl;
        }

        long long max_index = 0;
        long long max_value;
        for (long long j=0;j<m;j++){
            if ((prefix_a[j]+prefix_b[m-1]-prefix_b[j]+b[j]) > max_value){
                max_value = (prefix_a[j]+prefix_b[m-1]-prefix_b[j]+b[j]);
                max_index = j;
            }
        }

        //!I don't think I even have to trace since easy to calculate. 
        //!Interesting problem since just because I maximize Alice's score doesn't mean I minimize Bob's score. Goal isn't to maximize Alice's score. 
        //*Upsolve this one. 
        long long choice1 = prefix_a[m-1] - prefix_a[max_index];
        long long choice2 = prefix_b[max_index-1];
        cout << max(choice1, choice2) << "\n";
    }
}