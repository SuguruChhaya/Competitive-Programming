#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    //*Create a 1001 size vector to make it easier with the indexing. 
    vector <long long> buckets;
    for (int i=0;i<1001;i++){
        buckets.push_back(0);
    }

    long long n, s, t, b;
    cin >> n;

    for (long long i=0;i<n;i++){
        //*I cannot just overlapping add. 
        cin >> s >> t >> b;
        for (int i=s;i<=t;i++){
            buckets[i]+=b;
        }
    }

    long long result = 0;
    for (long long i=0;i<buckets.size();i++){
        result = max(result, buckets[i]);
    }

    cout << result << "\n";
}